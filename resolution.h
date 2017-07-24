/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 21:24:02 by rosanche          #+#    #+#             */
/*   Updated: 2017/07/24 11:49:13 by rosanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

typedef struct	s_quare
{
	int or_x;
	int or_y;
	int size;
}				t_square;

void		biggest_square_from_pos(int x, int y, char **tab, t_square *max);
char		**fill_map(char **tab, t_square *max);
void		find_square(char **tab, t_square *max, int x_max, int y_max);

#endif
