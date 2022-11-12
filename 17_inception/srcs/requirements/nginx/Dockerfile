FROM alpine:3.13

RUN	apk update && apk upgrade && apk add --no-cache \
    nginx      \
    openssl

# Nginx
RUN mkdir -p /run/nginx

EXPOSE 443 

COPY ./nginx/conf/default.conf /etc/nginx/conf.d/default.conf

RUN mkdir /etc/nginx/ssl && chmod 700 /etc/nginx/ssl 

COPY ./nginx/tools/certs /etc/nginx/ssl

ENTRYPOINT ["nginx", "-g", "daemon off;"]