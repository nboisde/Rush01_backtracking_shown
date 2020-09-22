/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constrains.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 01:17:02 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/20 19:53:23 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
** This function counts how many are visible downwards.
*/

char	v_col_up(char grid[4][5], int col)
{
	char	max_col;
	char	visible;
	int		i;

	max_col = '0';
	visible = '0';
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_col)
		{
			max_col = grid[i][col];
			visible++;
		}
		i++;
	}
	return (visible);
}

char	v_row_right(char grid[4][5], int row)
{
	char	max_row;
	char	visible;
	int		i;

	max_row = '0';
	visible = '0';
	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max_row)
		{
			max_row = grid[row][i];
			visible++;
		}
		i--;
	}
	return (visible);
}

char	v_col_down(char grid[4][5], int col)
{
	char	max_col;
	char	visible;
	int		i;

	max_col = '0';
	visible = '0';
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max_col)
		{
			max_col = grid[i][col];
			visible++;
		}
		i--;
	}
	return (visible);
}

char	v_row_left(char grid[4][5], int row)
{
	char	max_row;
	char	visible;
	int		i;

	max_row = '0';
	visible = '0';
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] > max_row)
		{
			max_row = grid[row][i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int		check_visible(char grid[4][5], char cons[4][5])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (cons[0][i] != v_col_up(grid, i))
			return (0);
		if (cons[1][i] != v_col_down(grid, i))
			return (0);
		if (cons[2][i] != v_row_left(grid, i))
			return (0);
		if (cons[3][i] != v_row_right(grid, i))
			return (0);
		i++;
	}
	return (1);
}
