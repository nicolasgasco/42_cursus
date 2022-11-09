FROM alpine:3.14


RUN apk update && apk upgrade && apk add --no-cache \
    mariadb \
    mariadb-server-utils \
    mariadb-client 

EXPOSE 3306


# From MariaDB official image
RUN rm -rf /var/lib/apt/lists/*; \
    rm -rf /var/lib/mysql; \
    mkdir -p /var/lib/mysql /var/run/mysqld; \
    chown -R mysql:mysql /var/lib/mysql /var/run/mysqld; \
    chmod 777 /var/run/mysqld

COPY tools/configure.sh /configure.sh

ENTRYPOINT [ "sh", "configure.sh" ]
