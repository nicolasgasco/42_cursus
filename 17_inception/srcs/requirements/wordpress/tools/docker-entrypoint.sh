#!/bin/sh

echo "[i] Wordpress env variables check:"
echo "    MYSQL_HOST: $MYSQL_HOST"
echo "    MYSQL_ROOT_PWD: $MYSQL_ROOT_PWD"
echo "    WP_DATABASE_NAME: $WP_DATABASE_NAME"
echo "    WP_DATABASE_USR: $WP_DATABASE_USR"
echo "    tWP_DATABASE_PWD: $WP_DATABASE_PWD"

if [ ! -f "/var/www/html/wordpress/wp-config.php" ]; then
    wp cli update

    echo "[i] Downloading Wordpress"
    wp core download --allow-root

    echo "[i] Create new wp-config.php file"
    echo "    dbname=$WP_DATABASE_NAME"
    echo "    dbuser=$WP_DATABASE_USR"
    echo "    dbpass=$WP_DATABASE_PWD"
    echo "    dbhost=$MYSQL_HOST"
    echo "    dbcharset=utf8"
    echo "    dbcollate=utf8_general_ci"
    wp config create --dbname=$WP_DATABASE_NAME --dbuser=$WP_DATABASE_USR --dbpass=$WP_DATABASE_PWD --dbhost=$MYSQL_HOST --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root

    echo "[i] Installing Wordpress with CLI"
    echo "    url=$DOMAIN_NAME/wordpress"
    echo "    title=$WP_TITLE"
    echo "    admin_user=$WP_ADMIN_USR"
    echo "    admin_password=$WP_ADMIN_PWD"
    echo "    admin_email=$WP_ADMIN_EMAIL"
    wp core install --url=$DOMAIN_NAME/wordpress --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root

    echo "[i] Creating new user"
    echo "    user=$WP_USR"
    echo "    email=$WP_EMAIL"
    echo "    role=author"
    echo "    user_pass=$WP_PWD"
    wp user create $WP_USR $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root
    
    echo "[i] Installing theme"
    wp theme install water-sports-club --activate --allow-root
else
    echo "[i] Wordpress already installed"
fi

echo "[i] Home page copied"
cp /tmp/index.html /var/www/html/

echo "[i] Wordpress started"
/usr/sbin/php-fpm7 -F -R