FROM alpine:3.14
RUN apk add nginx
COPY ./conf/conf.default /etc/nginx/conf.d/
RUN nginx -c /etc/nginx/conf.d/conf.default