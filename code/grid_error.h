/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:13:41 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/07/23 22:39:01 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_ERROR_H
# define GRID_ERROR_H

# include "convert.h"
# include <unistd.h>

int			grid_is_correct(t_list **begin_list, int x_max);

#endif
