/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 21:26:25 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/07/23 22:38:55 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

char		g_empty = 0;
char		g_obstacle = 0;
char		g_filled = 0;

void		get_chars(t_list **begin_list)
{
	t_list		*current_object;

	current_object = *begin_list;
	while (current_object && current_object->c != '\n')
	{
		g_empty = g_obstacle;
		g_obstacle = g_filled;
		g_filled = current_object->c;
		current_object = current_object->next;
	}
}

int			get_x_max(t_list **begin_list)
{
	t_list		*current_object;
	int			len;

	len = 0;
	current_object = *begin_list;
	while (current_object && current_object->c != '\n')
	{
		current_object = current_object->next;
		len++;
	}
	return (len);
}

int			get_y_max(t_list **begin_list)
{
	t_list		*current_object;
	int			len;

	len = 0;
	current_object = *begin_list;
	while (current_object)
	{
		len += (current_object->c == '\n');
		current_object = current_object->next;
	}
	return (len);
}
