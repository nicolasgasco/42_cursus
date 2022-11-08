#!/bin/sh

# From https://github.com/yobasystems/alpine-mariadb/blob/master/alpine-mariadb-armhf/files/run.sh
rm -rf /run/mysqld && rm -rf /var/lib/mysql/mysql

if [ -d "/run/mysqld" ]; then
    echo "[i] mysqld already present, skipping creation"
    chown -R mysql:mysql /run/mysqld
else
    echo "[i] mysqld not found, creating...."
    mkdir -p /run/mysqld
    chown -R mysql:mysql /run/mysqld
fi

if [ -d /var/lib/mysql/mysql ]; then
    echo "[i] MySQL directory already present, skipping creation"
    chown -R mysql:mysql /var/lib/mysql
    
    echo "[i] MySQL root Password: $MYSQL_ROOT_PASSWORD"
    echo "[i] MySQL database name is: $MYSQL_DATABASE"
    echo "[i] MySQL user is: $MYSQL_USER"
    echo "[i] MySQL password is: $MYSQL_PASSWORD"
else
    echo "[i] MySQL data directory not found, creating initial DBs"
    chown -R mysql:mysql /var/lib/mysql
    
    mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null
    
    MYSQL_DATABASE=${MYSQL_DATABASE:-""}
    MYSQL_USER=${MYSQL_USER:-""}
    MYSQL_PASSWORD=${MYSQL_PASSWORD:-""}
    
    tfile=`mktemp`
    
    cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES ;
GRANT ALL ON *.* TO 'root'@'%' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION ;
GRANT ALL ON *.* TO 'root'@'localhost' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION ;
SET PASSWORD FOR 'root'@'localhost'=PASSWORD('${MYSQL_ROOT_PASSWORD}') ;
DROP DATABASE IF EXISTS test ;
FLUSH PRIVILEGES ;
EOF
    
    if [ "$MYSQL_DATABASE" != "" ]; then
        echo "[i] Creating database: $MYSQL_DATABASE"
        
        echo "[i] with character set: 'utf8' and collation: 'utf8_general_ci'"
        echo "CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\` CHARACTER SET utf8 COLLATE utf8_general_ci;" >> $tfile
        
        echo "[i] Creating user: $MYSQL_USER with password $MYSQL_PASSWORD"
        echo "GRANT ALL ON \`$MYSQL_DATABASE\`.* to '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" >> $tfile
    fi
    
    /usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < $tfile
    rm -f $tfile
    
    for f in /docker-entrypoint-initdb.d/*; do
        case "$f" in
            *.sql)    echo "$0: running $f"; /usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < "$f"; echo ;;
            *.sql.gz) echo "$0: running $f"; gunzip -c "$f" | /usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < "$f"; echo ;;
            *)        echo "$0: ignoring or entrypoint initdb empty $f" ;;
        esac
        echo
    done
    
    echo
    echo 'MySQL init process done. Ready for start up.'
    echo
    
    echo "exec /usr/bin/mysqld --user=mysql --console --skip-name-resolve --skip-networking=0" "$@"
fi

# allow remote connections
sed -i "s|skip-networking|# skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

exec /usr/bin/mysqld --user=mysql --console --skip-name-resolve --skip-networking=0 $@
