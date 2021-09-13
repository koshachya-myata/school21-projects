/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 14:40:23 by vaztar            #+#    #+#             */
/*   Updated: 2020/03/15 20:42:14 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	g_res = 0;

int	match_help(char *s1, char *s2, unsigned int i, unsigned int j)
{
	if (s1[i] == '\0' && s2[j] == '\0')
	{
		g_res += 1;
		return (1);
	}
	if (s2[j] == '*' && s1[i] != '\0')
		return (match_help(s1, s2, i, j + 1) + match_help(s1, s2, i + 1, j));
	else if (s2[j] == '*' && s1[i] == '\0')
		return (match_help(s1, s2, i, j + 1));
	else if (s1[i] == s2[j])
		return (match_help(s1, s2, i + 1, j + 1));
	else
		return (0);
}

int	nmatch(char *s1, char *s2)
{
	g_res = 0;
	match_help(s1, s2, 0, 0);
	return (g_res);
}
