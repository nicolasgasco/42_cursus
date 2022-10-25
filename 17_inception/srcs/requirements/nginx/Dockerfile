FROM alpine:3.14
RUN apk update && apk add nginx && apk add php-fpm 
COPY ./conf/default.conf /etc/nginx/conf.d/
RUN nginx -c /etc/nginx/conf.d/default.conf