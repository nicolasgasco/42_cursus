FROM debian:buster

RUN	apt-get update -yq && apt-get upgrade -yq && apt-get install -yq \
    nginx      \
    openssl

EXPOSE 443

# Nginx
RUN mkdir -p /run/nginx
COPY conf/default.conf /etc/nginx/conf.d/default.conf

# SSL
RUN mkdir /etc/nginx/ssl && chmod 700 /etc/nginx/ssl 
RUN openssl req -newkey rsa:4096 -sha256 -x509 -nodes -days 365 \
    -subj "/C=ES/O=42/L=Urduliz\CN=Inception" \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt;

COPY tools/docker-entrypoint.sh /tmp/docker-entrypoint.sh

ENTRYPOINT ["sh", "/tmp/docker-entrypoint.sh"]