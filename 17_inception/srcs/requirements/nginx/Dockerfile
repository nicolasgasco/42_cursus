FROM alpine:3.14
RUN apk add nginx
RUN nginx -v
COPY ./conf /etc/nginx/conf.d/
RUN nginx -c /etc/nginx/conf.d/conf 