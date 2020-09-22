/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:10:40 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/22 15:37:04 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

int		ft_strlen(char *str);

int		valid_argument(int ac, char **av);

void	grid_constrains(char *str, char constrains[4][5]);

void	solution_grid(char grid[4][5]);

int		check_visible(char grid[4][5], char cons[4][5]);

int		col_not_twice(char grid[4][5], int val, int posx, int posy);

int		row_not_twice(char grid[4][5], int val, int posx, int posy);

int		process(char grid[4][5], char cons[4][5], int x, int y, int *step);

void	ft_print_grid(char grid[4][5]);

#include <stdio.h>

#endif
