# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 15:33:51 by vaztar            #+#    #+#              #
#    Updated: 2021/03/12 02:57:44 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

# BASICS
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget
RUN apt-get -y install vim
RUN apt-get install -y curl

# NGINX
RUN apt-get -y install nginx
COPY ./srcs/nginx.conf /etc/nginx/sites-available/localhost
RUN  ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
RUN unlink /etc/nginx/sites-enabled/default

# INSTALL MYSQL
RUN apt-get -y install mariadb-server

# PHP-
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

# SSL
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=RU/ST=Tatarstan/L=Kazan/O=School 21/OU=Developing/CN=vaztar'\
	-keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

# INSTALL PHPMYADMIN
WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.1/phpMyAdmin-4.9.1-english.tar.gz
RUN tar xf phpMyAdmin-4.9.1-english.tar.gz && rm -rf phpMyAdmin-4.9.1-english.tar.gz
RUN mv phpMyAdmin-4.9.1-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

# WP
RUN curl -O https://wordpress.org/latest.tar.gz
RUN tar xzvf latest.tar.gz
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

EXPOSE 80 443

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

COPY srcs/init_server.sh ./ 
RUN chmod 777 init_server.sh

RUN mkdir test && mkdir test/site
COPY srcs/index.html test/site
COPY srcs/switch_autoindex.sh ./
RUN chmod 777 switch_autoindex.sh
CMD bash ./init_server.sh
