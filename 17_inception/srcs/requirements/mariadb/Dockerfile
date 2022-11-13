FROM alpine:3.14

RUN apk update && apk upgrade && apk add --no-cache \
    mariadb \
    mariadb-client 
COPY tools/configure.sh /tmp/configure.sh

ENTRYPOINT [ "sh", "/tmp/configure.sh" ]
