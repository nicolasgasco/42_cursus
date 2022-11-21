#!/bin/sh

echo "[i] mariadb env variables check:"
echo "    MYSQL_HOST: $MYSQL_HOST"
echo "    MYSQL_ROOT_PWD: $MYSQL_ROOT_PWD"
echo "    WP_DATABASE_NAME: $WP_DATABASE_NAME"
echo "    WP_DATABASE_USR: $WP_DATABASE_USR"
echo "    tWP_DATABASE_PWD: $WP_DATABASE_PWD"

# From https://github.com/yobasystems/alpine-mariadb/blob/master/alpine-mariadb-armhf/files/run.sh
if [ -d "/run/mysqld" ]; then
    echo "[i] mysqld directory already present, skipping creation"
    chown -R mysql:mysql /run/mysqld
else
    echo "[i] mysqld directory not found, creating"
    mkdir -p /run/mysqld
    chown -R mysql:mysql /run/mysqld
fi

if [ -d /var/lib/mysql/mysql ]; then
    echo "[i] MySQL directory already present, skipping creation"
    chown -R mysql:mysql /var/lib/mysql
    
else
    echo "[i] MySQL directory not found, creating initial DBs"
    chown -R mysql:mysql /var/lib/mysql
    
    echo "[i] Creating system tables"
    mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null
    
    tfile=`mktemp`
    
    cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES ;
GRANT ALL ON *.* TO 'root'@'%' identified by '$MYSQL_ROOT_PWD' WITH GRANT OPTION ;
GRANT ALL ON *.* TO 'root'@'localhost' identified by '$MYSQL_ROOT_PWD' WITH GRANT OPTION ;
SET PASSWORD FOR 'root'@'localhost'=PASSWORD('${MYSQL_ROOT_PWD}') ;
DROP DATABASE IF EXISTS test ;
FLUSH PRIVILEGES ;
EOF
    
	if [ "$WP_DATABASE_NAME" != "" ]; then
	    echo "[i] Creating database: $WP_DATABASE_NAME"
        echo "[i] with character set: 'utf8' and collation: 'utf8_general_ci'"
        echo "CREATE DATABASE IF NOT EXISTS \`$WP_DATABASE_NAME\` CHARACTER SET utf8 COLLATE utf8_general_ci;" >> $tfile
	 if [ "$WP_DATABASE_USR" != "" ]; then
		echo "[i] Creating user: $WP_DATABASE_USR with password $WP_DATABASE_PWD"
		echo "GRANT ALL ON \`$WP_DATABASE_NAME\`.* to '$WP_DATABASE_USR'@'%' IDENTIFIED BY '$WP_DATABASE_PWD';" >> $tfile
	    fi
	fi
    
    /usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < $tfile
    rm -f $tfile
    echo 'MySQL init process done. Ready for start up.'
fi

# allow remote connections
sed -i "s|skip-networking|# skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

exec /usr/bin/mysqld --user=mysql --console --skip-name-resolve --skip-networking=0
