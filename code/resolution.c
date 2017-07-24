/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:06:19 by rosanche          #+#    #+#             */
/*   Updated: 2017/07/24 13:38:28 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolution.h"
#include <unistd.h>

extern char		g_empty;
extern char		g_obstacle;
extern char		g_filled;

void		find_square(char **tab, int x_max, int y_max)
{
	int			x;
	int			y;
	t_square	*max;
	t_map		*map;

	x = 0;
	y = 0;
	map = malloc(sizeof(t_map));
	map->map = tab;
	map->x_max = x_max;
	map->y_max = y_max;
	max = malloc(sizeof(t_square));
	max->or_x = 0;
	max->or_y = 0;
	max->size = 0;
	while (x < x_max && y < y_max)
	{
		biggest_square_from_pos(x, y, map, max);
		if (x == x_max - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	fill_map(tab, max);
}

void		biggest_square_from_pos(int x, int y, t_map *map, t_square *max)
{
	char	**tab;
	int	size;
	int i;
	int j;

	tab = map->map;
	size = 1;
	i = x;
	j = y;
	if (tab[y][x] == g_obstacle)
		return ;
	while (i < map->x_max && j < map->y_max 
			&& tab[j][i] != g_obstacle && tab[j][i] != '\n')
	{
		if (i == x + size - 1 && j == y + size - 1)
		{
			size++;
			i = x;
			j = y;
		}
		else if (i == x + size - 1)
		{
			j++;
			i = x;
		}
		else
			i++;
	}
	if (size - 1 > max->size)
	{
		max->or_x = x;
		max->or_y = y;
		max->size = size - 1;
	}
}

void		fill_map(char **tab, t_square *max)
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
		tab[j][i] = g_filled;
		if (i == x + max->size - 1)
		{
			j++;
			i = x;
		}
		else
			i++;
	}
}
