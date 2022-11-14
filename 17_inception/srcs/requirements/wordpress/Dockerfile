FROM alpine:3.14

RUN apk update && apk upgrade && apk add --no-cache \
    mariadb-client		\
    curl                \
    php7				\
    php7-fpm			\
    php7-bcmath			\
    php7-bz2 			\
    php7-calendar		\
    php7-ctype			\
    php7-curl			\
    php7-dom			\
    php7-exif			\
    php7-fileinfo		\
    php7-gd				\
    php7-gmagick		\
    php7-gmp			\
    php7-iconv			\
    php7-imap			\
    php7-intl			\
    php7-json			\
    php7-mbstring		\
    php7-mcrypt			\
    php7-memcache		\
    php7-mysqli			\
    php7-mysqlnd		\
    php7-openssl		\
    php7-pcntl			\
    php7-pdo			\
    php7-pdo_mysql		\
    php7-pdo_pgsql		\
    php7-pdo_sqlite 	\
    php7-pgsql			\
    php7-phar			\
    php7-posix			\
    php7-session		\
    php7-shmop			\
    php7-simplexml		\
    php7-soap			\
    php7-sockets		\
    php7-sodium			\
    php7-sqlite3		\
    php7-sysvsem		\
    php7-sysvshm		\
    php7-tokenizer		\
    php7-xml			\
    php7-xmlreader		\
    php7-xmlwriter		\
    php7-xsl			\
    php7-zip			\
    php7-zlib			

# Conf
RUN	adduser -S nginx &&	addgroup -S nginx
COPY conf/php-fpm.conf /etc/php7/php-fpm.conf
COPY conf/www.conf /etc/php7/php-fpm.d/www.conf

# Install WP CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN php wp-cli.phar --allow-root
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# Custom index page
COPY ./tools/homepage/index.html /tmp/index.html

COPY ./tools/docker-entrypoint.sh /tmp/docker-entrypoint.sh

WORKDIR /var/www/html/wordpress

ENTRYPOINT ["sh", "/tmp/docker-entrypoint.sh"]