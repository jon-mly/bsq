/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:09:05 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/07/23 22:38:59 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"


#include <stdio.h>

extern char		g_empty;
extern char		g_obstacle;
extern char		g_filled;

int			correct_chars(t_list **begin_list)
{
	t_list		*current_object;
	char		c;

	current_object = *begin_list;
	while (current_object)
	{
		c = current_object->c;
		if (c != g_empty || c != g_obstacle || c != '\n')
			return (0);
		current_object = current_object->next;
	}
	return (1);
}

int			correct_line_length(t_list **begin_list, int x_max)
{
	t_list		*current_object;
	int			length;

	current_object = *begin_list;
	length = 0;
	while (current_object)
	{
		if (current_object->c == '\n')
		{
			if (length != x_max)
				return (0);
			length = 0;
		}
		else
			length++;
		current_object = current_object->next;
	}
	return (1);
}

int			correct_size(t_list **begin_list)
{
	t_list		*current_object;

	current_object = *begin_list;
	return (current_object->c == g_empty || current_object->c == g_obstacle);
}

int			grid_is_correct(t_list **begin_list, int x_max)
{
	printf("%d\n", correct_chars(begin_list));
	printf("%d\n", correct_line_length(begin_list, x_max));
	printf("%d\n", correct_size(begin_list));

	if (correct_chars(begin_list)
			&& correct_line_length(begin_list, x_max)
			&& correct_size(begin_list))
		return (1);
	write(1, "map error\n", 10);
	return (0);
}
