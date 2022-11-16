FROM alpine:3.14

RUN apk update && apk upgrade && apk add --no-cache \
    mariadb-client		\
    curl                \
    php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-phar php7-json php7-iconv

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