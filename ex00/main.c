/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:47:52 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/22 15:36:12 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putline(char *line)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putchar(line[i]);
		if (!(i == 3))
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
}

void	ft_print_grid(char grid[4][5])
{
	int y;

	y = 0;
	while (y < 4)
	{
		ft_putline(grid[y]);
		y++;
	}
}

void	ft_puterror(void)
{
	write(1, "Error\n", 6);
}

int		main(int ac, char **av)
{
	char	cons[4][5];
	char	grid[4][5];
	int		step;

	step = 0;
	if (valid_argument(ac, av))
	{
		grid_constrains(av[1], cons);
		solution_grid(grid);
		if ((process(grid, cons, 0, 0, &step)))
		{
			//ft_print_grid(grid);
			int i;
			i = 0;
			while (i < 4)
			{
				printf("%s\n", grid[i]);
				i++;
			}
			return (1);
		}
	}
	ft_puterror();
	return (0);
}
