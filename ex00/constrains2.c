/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constrains2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:34:11 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/20 18:04:24 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		col_not_twice(char grid[4][5], int val, int posx, int posy)
{
	int		y;

	y = 0;
	while (y < 4)
	{
		if (!(y == posy) && grid[y][posx] == val)
			return (0);
		y++;
	}
	return (1);
}

int		row_not_twice(char grid[4][5], int val, int posx, int posy)
{
	int		x;

	x = 0;
	while (x < 4)
	{
		if (!(x == posx) && grid[posy][x] == val)
			return (0);
		x++;
	}
	return (1);
}
