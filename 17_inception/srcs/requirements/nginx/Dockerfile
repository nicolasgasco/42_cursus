FROM alpine:3.13

RUN	apk update && apk upgrade && apk add --no-cache \
    nginx      \
    openssl

# Nginx
RUN mkdir -p /run/nginx
COPY ./nginx/conf/default.conf /etc/nginx/conf.d/default.conf

# SSL
RUN mkdir /etc/nginx/ssl && chmod 700 /etc/nginx/ssl 
COPY ./nginx/tools/certs /etc/nginx/ssl

COPY ./nginx/tools/docker-entrypoint.sh /tmp/docker-entrypoint.sh

ENTRYPOINT ["sh", "/tmp/docker-entrypoint.sh"]