/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <vaztar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:51:29 by vaztar            #+#    #+#             */
/*   Updated: 2021/04/07 17:41:15 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

char s1[] = "1234";
char s2[] = "";
char s3[] = "Lorem ipsum dolor sit amet, \
	consectetur adipiscing elit. \
	Nunc sit amet aliquam lorem. \
	Mauris molestie eu turpis non commodo. \
	Suspendisse vehicula commodo laoreet. \
	Quisque a metus vestibulum, tincidunt ipsum dignissim, maximus dolor. \
	Fusce eu dui finibus, gravida enim a, tempus mauris. Nam pharetra ante volutpat maximus ornare. \
	Curabitur vitae leo purus. Vestibulum ante ipsum primis in faucibus orci luctus et.";

void	check_strlen()
{
	printf("\nCHECK FT_STRLEN:\n");
	printf("String: '%s'\n", s1);
	printf("FT: %zu\n", ft_strlen(s1));
	printf("ORIG: %zu\n---------------\n", strlen(s1));

	printf("String: '%s'\n", s2);
	printf("FT: %zu\n", ft_strlen(s2));
	printf("ORIG: %zu\n---------------\n", strlen(s2));

	printf("String: '%s'\n", s3);
	printf("FT: %zu\n", ft_strlen(s3));
	printf("ORIG: %zu\n---------------\n", strlen(s3));
}

void	check_strcmp()
{
	printf("\nCHECK FT_STRCMP:\n");
	printf("'12345', '12345'\n");
	printf("FT: %d\n", ft_strcmp("12345", "12345"));
	printf("ORIG: %d\n---------------\n", strcmp("12345", "12345"));

	printf("'', ''\n");
	printf("FT: %d\n", ft_strcmp("", ""));
	printf("ORIG: %d\n---------------\n", strcmp("", ""));

	printf("'12345', ''\n");
	printf("FT: %d\n", ft_strcmp("12345", ""));
	printf("ORIG: %d\n---------------\n", strcmp("12345", ""));

	printf("'', '1'\n");
	printf("FT: %d\n", ft_strcmp("", "1"));
	printf("ORIG: %d\n---------------\n", strcmp("", "1"));

	printf("'abcd', 'abcde'\n");
	printf("FT: %d\n", ft_strcmp("abcd", "abcde"));
	printf("ORIG: %d\n---------------\n", strcmp("abcd", "abcde"));

	printf("'qwer', 'qwQr'\n");
	printf("FT: %d\n", ft_strcmp("qwer", "qwQr"));
	printf("ORIG: %d\n---------------\n", strcmp("qwer", "qwQr"));
}

void	check_strcpy()
{
	char *dst = (char*)malloc(5);
	char dest[500];
	printf("\nCHECK FT_STRCPY:\n");
	
	printf("String: 1234'\n");
	printf("FT: %s\n", ft_strcpy(dst, "1234"));
	printf("ORIG: %s\n---------------\n", strcpy(dst, "1234"));

	printf("String: '%s'\n", s1);
	printf("FT: %s\n", ft_strcpy(dest, s1));
	printf("ORIG: %s\n---------------\n", strcpy(dest, s1));

	printf("String: '%s'\n", s2);
	printf("FT: %s\n", ft_strcpy(dest, s2));
	printf("ORIG: %s\n---------------\n", strcpy(dest, s2));

	printf("String: '%s'\n", s3);
	printf("FT: %s\n", ft_strcpy(dest, s3));
	printf("ORIG: %s\n---------------\n", strcpy(dest, s3));
	free(dst);
}

void	check_write()
{
	printf("\nCHECK WRITE:\n");
	
	printf("String: '%s'\n", s1);
	printf("FT: %zu\n", ft_write(1, s1, 5));
	perror("Write error?");
	printf("ORIG: %zu\n", write(1, s1, 5));
	perror("Write error?");
	printf("-----------------------------------\n");

	printf("String: '%s'\n", s2);
	printf("FT: %zu\n", ft_write(1, s2, 1));
	perror("Write error?");
	printf("ORIG: %zu\n", write(1, s2, 1));
	perror("Write error?");
	printf("-----------------------------------\n");

	printf("String: '%s'\n", s3);
	printf("FT: %zu\n", ft_write(1, s3, 420));
	perror("Write error?");
	printf("ORIG: %zu\n", write(1, s3, 420));
	perror("Write error?");
	printf("-----------------------------------\n");

	printf("Check errors: give fd = 42\n");
	printf("FT: %zu\n", ft_write(42, s2, 1));
	perror("Write error?");
	errno = 0;
	printf("ORIG: %zu\n", write(42, s2, 1));
	perror("Write error?");
	printf("-----------------------------------\n");
}

void	check_read()
{
	errno = 0;
	char *dst = (char*)malloc(5);
	printf("\nCHECK READ:\n");
	
	printf("CHECK STD\n");
	printf("FT: %zu\n", ft_read(2, dst, 5));
	perror("Read error?");
	printf("ORIG: %zu\n", read(2, dst, 5));
	perror("Read error?");
	printf("-----------------------------------\n");
	
	int fd = open("ft_read.s", O_RDONLY);
	printf("Open ft_read.s\n");
	printf("FT: %zu\n", ft_read(fd, dst, 5));
	printf("%s", dst);
	printf("\n");
	perror("Read error?");
	fd = open("ft_read.s", O_RDONLY);
	printf("ORIG: %zu\n", read(fd, dst, 5));
	printf("%s", dst);
	printf("\n");
	perror("Read error?");
	printf("-----------------------------------\n");

	printf("Open fd = -1\n");
	printf("FT: %zu\n", ft_read(-1, dst, 5));
	perror("Read error?");
	errno = 0;
	printf("ORIG: %zu\n", read(-1, dst, 5));
	perror("Read error?");
	printf("-----------------------------------\n");
	free(dst);
}

void	check_strdup()
{
	printf("\nCHECK FT_STRDUP:\n");
	
	printf("String: '1'\n");
	char *str1 = ft_strdup("1");
	printf("%s\n", str1);

	printf("String: '%s'\n", s1);
	char *str2 = ft_strdup(s1);
	printf("%s\n", str2);

	printf("String: '%s'\n", s2);
	char *str3 = ft_strdup(s2);
	printf("%s\n", str3);

	printf("String: '%s'\n", s3);
	char *str4 = ft_strdup(s3);
	printf("%s\n", str4);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	
}

int	main(void)
{

	check_strlen();
	check_strcmp();
	check_strcpy();
	check_write();
	check_read();
	check_strdup();
}