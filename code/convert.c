/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:45:38 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/07/23 22:01:51 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

void		delete_first_line(t_list **begin_list)
{
	t_list		*current_object;

	current_object = *begin_list;
	while (current_object->c != '\n')
	{
		*begin_list = current_object->next;
		free(current_object);
		current_object = *begin_list;
	}
	*begin_list = current_object->next;
	free(current_object);
}

t_list		**init_chained(int fd)
{
	t_list		**begin_list;
	t_list		*current_object;
	t_list		*new_object;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char));
	begin_list = (t_list **)malloc(sizeof(t_list *));
	current_object = 0;
	while (read(fd, buffer, 1))
	{
		new_object = (t_list *)malloc(sizeof(t_list));
		new_object->c = *buffer;
		new_object->next = 0;
		if (current_object)
		{
			current_object->next = new_object;
			current_object = current_object->next;
		}
		else
		{
			*begin_list = new_object;
			current_object = *begin_list;
		}
	}
	return (begin_list);
}

char		**convert_chained(t_list **begin_list, int x_max, int y_max)
{
	t_list		*current_object;
	char		**tab;
	int			x;
	int			y;

	if (!(tab = (char **)malloc((y_max + 1) * sizeof(char *))))
		return (0);
	x = 0;
	y = 0;
	while ((current_object = *begin_list))
	{
		if (x == 0)
			tab[y] = (char *)malloc((x_max + 2) * sizeof(char));
		tab[y][x] = current_object->c;
		y = (current_object->c == '\n') ? y + 1 : y;
		x = (current_object->c == '\n') ? 0 : x + 1;
		*begin_list = current_object->next;
		free(current_object);
	}
	return (tab);
}
