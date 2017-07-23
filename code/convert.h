/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:44:47 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/07/23 22:02:07 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

#include <stdlib.h>
#include <unistd.h>

typedef struct		s_list
{
	char			c;
	struct s_list	*next;
}					t_list;

t_list		**init_chained(int fd);
char		**convert_chained(t_list **begin_list, int x_max, int y_max);
void		delete_first_line(t_list **begin_list);


#endif
