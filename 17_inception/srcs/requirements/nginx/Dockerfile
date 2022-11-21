FROM alpine:3.15

RUN	apk update && apk upgrade && apk add --no-cache \
    nginx      \
    openssl

EXPOSE 443

# Nginx
RUN mkdir -p /run/nginx
COPY ./nginx/conf/default.conf /etc/nginx/conf.d/default.conf

# SSL
RUN mkdir /etc/nginx/ssl && chmod 700 /etc/nginx/ssl 
# COPY ./nginx/tools/certs /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 \
    -subj  "/C=ES/O=42/L=Urduliz\CN=Inception" \
    -newkey rsa:2048 -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt;

COPY ./nginx/tools/docker-entrypoint.sh /tmp/docker-entrypoint.sh

ENTRYPOINT ["sh", "/tmp/docker-entrypoint.sh"]