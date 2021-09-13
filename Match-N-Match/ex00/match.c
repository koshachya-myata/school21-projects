/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:46:12 by vaztar            #+#    #+#             */
/*   Updated: 2020/03/15 20:41:51 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match_help(char *s1, char *s2, unsigned int i, unsigned int j)
{
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	if (s2[j] == '*' && s1[i] != '\0')
		return (match_help(s1, s2, i, j + 1) || match_help(s1, s2, i + 1, j));
	else if (s2[j] == '*' && s1[i] == '\0')
		return (match_help(s1, s2, i, j + 1));
	else if (s1[i] == s2[j])
		return (match_help(s1, s2, i + 1, j + 1));
	else
		return (0);
}

int	match(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	int				res;

	i = 0;
	j = 0;
	res = match_help(s1, s2, i, j);
	return (res);
}
