FROM alpine:3.14
RUN apk update && apk add nginx && apk add php-fpm
# && docker-php-ext-install mysqli pdo pdo_mysql && docker-php-ext-enable pdo_mysql
ADD ./conf/default.conf /etc/nginx/conf.d/default.conf
ADD ./tools/certs /etc/nginx/certs/self-signed
