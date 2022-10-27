FROM alpine:3.14
RUN wget https://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && mkdir wordpress-files && cp -r wordpress/* wordpress-files/ && rm -rf wordpress/
RUN apk update && apk upgrade && apk add php7 php7-fpm php7-opcache