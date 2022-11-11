FROM alpine:3.14

RUN apk update && apk upgrade && apk add --no-cache \
    mariadb \
    mariadb-client 

EXPOSE 3306


COPY tools/configure.sh /tmp/configure.sh

ENTRYPOINT [ "sh", "/tmp/configure.sh" ]
