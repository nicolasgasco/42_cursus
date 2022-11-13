#!/bin/sh

echo "[i] Wordpress env variables check:"
echo "    MYSQL_HOST: $MYSQL_HOST"
echo "    MYSQL_ROOT_PWD: $MYSQL_ROOT_PWD"
echo "    WP_DATABASE_NAME: $WP_DATABASE_NAME"
echo "    WP_DATABASE_USR: $WP_DATABASE_USR"
echo "    tWP_DATABASE_PWD: $WP_DATABASE_PWD"

if [ ! -f "/var/www/html/wordpress/wp-config.php" ]; then
    echo "[i] Installing Wordpress with CLI"
    wp cli update
    wp core download --allow-root
    wp config create --dbname=$WP_DATABASE_NAME --dbuser=$WP_DATABASE_USR --dbpass=$WP_DATABASE_PWD --dbhost=$MYSQL_HOST --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
    wp core install --url=$DOMAIN_NAME/wordpress --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
    wp user create $WP_USR $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root
    wp plugin update --all --allow-root
else
    echo "[i] Wordpress already installed"
fi

echo "[i] Home page copied"
cp /tmp/index.html /var/www/html/

echo "[i] Wordpress started"
/usr/sbin/php-fpm7 -F -R