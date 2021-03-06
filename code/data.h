/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 21:27:18 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/07/24 10:39:28 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "convert.h"

int			get_x_max(t_list **begin_list);
int			get_y_max(t_list **begin_list);
void		get_chars(t_list **begin_list);

#endif
