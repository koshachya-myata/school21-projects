# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init_server.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 02:37:02 by vaztar            #+#    #+#              #
#    Updated: 2021/03/12 02:37:04 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Start
service nginx start
service mysql start
service php7.3-fpm start

# Config a WP DB
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

bash