FROM alpine:3.13

RUN	apk update \
    && apk upgrade \
    && apk add --no-cache \
    nginx

RUN mkdir -p /run/nginx

EXPOSE 443 

COPY ./nginx/conf/default.conf /etc/nginx/conf.d/default.conf
COPY ./nginx/conf/index.html /var/www/html/index.html

CMD ["nginx", "-g", "daemon off;"]