/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 21:24:02 by rosanche          #+#    #+#             */
/*   Updated: 2017/07/24 13:27:15 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

# include <stdlib.h>

typedef struct	s_quare
{
	int		or_x;
	int		or_y;
	int		size;
}				t_square;

typedef struct	s_map
{
	char	**map;
	int		x_max;
	int		y_max;
}				t_map;

void		biggest_square_from_pos(int x, int y, t_map *map, t_square *max);
void		fill_map(char **tab, t_square *max);
void		find_square(char **tab, int x_max, int y_max);

#endif
