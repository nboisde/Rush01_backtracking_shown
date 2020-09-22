/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:12:00 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/20 17:49:35 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
** This Functions tests argument validity.
*/

int		valid_argument(int ac, char **av)
{
	int i;

	i = 0;
	if (ac != 2)
		return (0);
	if (ac == 2)
	{
		if (ft_strlen(av[1]) != 31)
			return (0);
		while (av[1][i] && i <= 31)
		{
			if (i % 2 == 0)
			{
				if (!(av[1][i] >= '1' && av[1][i] <= '4'))
					return (0);
			}
			else
			{
				if (av[1][i] != ' ')
					return (0);
			}
			i++;
		}
	}
	return (1);
}

/*
** This function reads the argument and transform it into a 4x4 grid.
*/

void	grid_constrains(char *str, char constrains[4][5])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			constrains[j][k] = str[i];
			k++;
			i += 2;
		}
		constrains[j][k] = '\0';
		j++;
	}
}

/*
** This function create the grid of solution filled with '0'.
*/

void	solution_grid(char grid[4][5])
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			grid[y][x] = '0';
			x++;
		}
		grid[y][x] = '\0';
		y++;
	}
}
