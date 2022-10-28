FROM alpine:3.14
RUN wget https://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm -rf latest.tar.gz
RUN mkdir /var/www && mkdir /var/www/html
RUN cp -r wordpress/* var/www/html/ && rm -rf wordpress
RUN apk update && apk upgrade && apk add php7 php7-fpm php7-opcache