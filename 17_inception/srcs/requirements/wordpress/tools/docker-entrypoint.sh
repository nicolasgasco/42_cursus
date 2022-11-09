#!/bin/sh

if [ ! -f "/var/www/html/wp-config.php" ]; then
    
    echo "[i] Installing Wordpress"
    wp core download --allow-root
    wp config create --dbname="wp" --dbuser="wp" --dbpass="secret" --dbhost="mariadb:3306" --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
    wp core install --url=$DOMAIN_NAME/wordpress --title="db" --admin_user="wp" --admin_password="secret" --admin_email="test@test.com" --skip-email --allow-root
    # wp user create "user" "user@test.com" --role=author --user_pass="secret" --allow-root
fi
echo "Wordpress started on :9000"
/usr/sbin/php-fpm7 -F -R