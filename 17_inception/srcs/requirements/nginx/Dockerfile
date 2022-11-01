FROM alpine:3.13

RUN	apk update \
    && apk upgrade \
    && apk add --no-cache \
    nginx

RUN mkdir -p /run/nginx
COPY ./nginx/conf/default.conf /etc/nginx/conf.d/default.conf

CMD ["nginx", "-g", "daemon off;"]