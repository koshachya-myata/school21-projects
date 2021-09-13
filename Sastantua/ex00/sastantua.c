/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaztar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:32:36 by vaztar            #+#    #+#             */
/*   Updated: 2020/03/08 17:06:16 by vaztar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		base(int lvl)
{
	int	append_strs;
	int	strs_in_lvl;

	if (lvl == 1)
		return (5);
	append_strs = ((lvl / 2) + 2) * 2;
	strs_in_lvl = 2 + lvl;
	return (strs_in_lvl * 2 - 2 + append_strs + base(lvl - 1));
}

void	print_str(int lvl, int num, int endlvl)
{
	int base_lvl;
	int endlvl_base;
	int void_c;
	int i;
	int strs_c;

	base_lvl = base(lvl);
	endlvl_base = base(endlvl);
	void_c = (endlvl_base - base_lvl) / 2 + lvl + 2 - num;
	i = -1;
	strs_c = base_lvl - (lvl + 2 - num) * 2;
	while (++i < void_c)
		ft_putchar(' ');
	ft_putchar('/');
	i = -1;
	while (++i < strs_c)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	print_door_str(int lvl, int door, int i)
{
	int j;

	j = -1;
	while (++j < door - i)
		ft_putchar(' ');
	ft_putchar('/');
	j = -1;
	while (++j < ((base(lvl) - door) / 2 - (door - i)))
		ft_putchar('*');
	j = 0;
	while (++j < door - 1)
		ft_putchar('|');
	if (door >= 5 && i == door / 2 + 1)
		ft_putchar('$');
	else
		ft_putchar('|');
	if (door > 1)
		ft_putchar('|');
	j = -1;
	while (++j < ((base(lvl) - door) / 2 - (door - i)))
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	print_lvl(int lvl, int endlvl)
{
	int i;
	int door;

	i = 0;
	door = (lvl - 1) + lvl % 2;
	if (lvl != endlvl)
		while (++i <= lvl + 2)
			print_str(lvl, i, endlvl);
	else
	{
		i = 0;
		while (++i <= (lvl + 2) - door)
			print_str(lvl, i, endlvl);
		i = 0;
		while (++i <= door)
			print_door_str(lvl, door, i);
	}
}

void	sastantua(int size)
{
	int i;

	i = 0;
	while (++i <= size)
		print_lvl(i, size);
}
