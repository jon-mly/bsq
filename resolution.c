/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:06:19 by rosanche          #+#    #+#             */
/*   Updated: 2017/07/24 11:59:46 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolution.h"
#include <unistd.h>


#include <stdio.h>

char		**fill_map(char **tab, t_square *max);

void		find_square(char **tab, t_square *max, int x_max, int y_max)
{
	int			x;
	int			y;

	x = 0 ;
	y = 0 ;
	while (x < x_max && y < y_max)
	{
		biggest_square_from_pos(x, y, tab, max);
		if (x == x_max - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
}

void		biggest_square_from_pos(int x, int y, char **tab, t_square *max)
{
	int	size;
	int i;
	int j;

	size = 1;
	i = x;
	j = y;
	if (tab[y][x] == 'o')
		return ;
	while (tab[j][i] != 'o' && tab[j][i] != '\n')
	{
		if (i == x + size - 1 && j == y + size - 1)
		{
//			write(1, "a", 1);
			size++;
			i = x;
			j = y;
//			tab = fill_map(tab, max);
		}
		else if (i == x + size - 1)
		{
//			write(1, "c", 1);
			j++;
			i = x;
		}
		else
		{
//			write(1, "d", 1);
			i++;
		}
	}
	if (size - 1 > max->size)
	{
		max->or_x = x;
		max->or_y = y;
		max->size = size - 1;
	}

//	printf("x: %d, y: %d, size: %d\n", max->or_x, max->or_y, max->size);
//	while (tab[x][y])
//	tab[i][j] == 'o' ? biggest_square_from_pos(x, y + 1, tab, max) : biggest_square_from_pos(x + 1, y, tab, max);
//	write(1, "HEIN", 4);
//	tab = fill_map(tab, max);
//	return (tab);
}

char		**fill_map(char **tab, t_square *max)
{
	int x;
	int y;
	int i;
	int j;

	x = max->or_x;

	y = max->or_y;
	i = x;
	j = y;
	while (i < x + max->size && j < y + max->size)
	{
//		write(1, "HEIN", 4);
		tab[j][i] = 'x';
		if (i == x + max->size - 1)
		{
			j++;
			i = x;
		}
		else
			i++;
//		j = (j == y + max->size) ? y : j + 1;
//		i = (j == y + max->size) ? i + 1 : i;
	}
	return (tab);
}
