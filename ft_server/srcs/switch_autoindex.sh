# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    switch_autoindex.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 01:17:41 by vaztar            #+#    #+#              #
#    Updated: 2021/03/12 02:37:08 by vaztar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if grep -q "autoindex on" ../../../etc/nginx/sites-available/localhost
then
	sed -i "s|autoindex on|autoindex off|g" \
			../../../etc/nginx/sites-available/localhost
	service nginx reload
elif grep -q "autoindex off" ../../../etc/nginx/sites-available/localhost
then
	sed -i "s|autoindex off|autoindex on|g" \
			../../../etc/nginx/sites-available/localhost
service nginx reload
fi