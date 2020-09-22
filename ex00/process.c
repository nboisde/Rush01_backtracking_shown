/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:25:01 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/22 15:43:35 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
//#include <stdio.h>

int		process(char grid[4][5], char cons[4][5], int x, int y, int *step)
{
	char	i;

	printf("\nstarting the function process recursively.\n");
	i = '1';
	printf("Is the grid valid ?? %i (0 not valid, 1 ok)\n", check_visible(grid, cons));
	if (x == 4)
	{
		if (y == 3)
		{
			if (check_visible(grid, cons))
			{
				printf("\nOUR FINAL SOLUTION IS:\n");
				return (check_visible(grid, cons));
			}
		}
		y++;
		x = 0;
		printf("\nWe move to the next row because we just filled all the previous one.\n");
	}
	while (i <= '4')
	{
		printf("\n------------------------------------\n");
		printf("\nSTEP:\t%i\n", *step);
		printf("\ncoordinates x: %i, y: %i", x, y);
		printf("\ntower i we are trying to put: %c\n", i);
		printf("Is the number already exists in col ? %i (0 not valid, 1 ok)\n", col_not_twice(grid, i, x, y));
		printf("Is the number already exists in row ? %i (0 not valid, 1 ok)\n", row_not_twice(grid, i, x, y));
		printf("\n-----The grid:-----\n");
		//ft_print_grid(grid);
		int j;
		j = 0;
		while (j < 4)
		{
			printf("%s\n", grid[j]);
			j++;
		}
		printf("\n");
		if (col_not_twice(grid, i, x, y) && row_not_twice(grid, i, x, y))
		{
			printf("we put the tower\n");
			grid[y][x] = i;
			if (process(grid, cons, x + 1, y, step))
				return (1);
			else
				printf("Lets backtrack -------->");
		}
		(*step)++;
		i++;
		printf("WE GO TO THE STEP -> %i\n", *step);
	}
	grid[y][x] = '0';
	return (0);
}
