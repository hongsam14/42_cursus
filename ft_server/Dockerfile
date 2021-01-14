FROM debian:buster
LABEL maintainer="suhong@student.42seoul.kr"

RUN apt-get update && apt-get install -y	nginx\
	    					php\
						php-fpm\
						php-mbstring\
						php-mysql\
						mariadb-server\
						openssl
COPY ./src/start.sh ./
COPY ./src/default_org ./
COPY ./src/autoindex.sh ./
COPY ./src/config.inc.php ./
COPY ./src/wp-config.php ./
COPY ./src/phpMyAdmin-4.9.0.1-all-languages.tar.gz ./
COPY ./src/latest.tar.gz ./

CMD bash ./start.sh

EXPOSE 80
EXPOSE 443
