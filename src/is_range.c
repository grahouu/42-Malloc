/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:12:21 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:12:21 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

t_bool	is_range(const t_meta range)
{
	if (range.type == TRANGE
		|| range.type == SRANGE
		|| range.type == LRANGE)
		return (TRUE);
	return (FALSE);
}
