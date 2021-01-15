FROM debian:buster
LABEL maintainer="suhong@student.42seoul.kr"

RUN apt-get update && apt-get install -y	nginx\
	    					php\
						php-fpm\
						php-mbstring\
						php-mysql\
						mariadb-server\
						openssl
COPY ./srcs/start.sh ./
COPY ./srcs/default_org ./
COPY ./srcs/autoindex.sh ./
COPY ./srcs/config.inc.php ./
COPY ./srcs/wp-config.php ./
COPY ./srcs/phpMyAdmin-4.9.0.1-all-languages.tar.gz ./
COPY ./srcs/latest.tar.gz ./

CMD bash ./start.sh

EXPOSE 80
EXPOSE 443
