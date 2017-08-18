/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_slice_or_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:12:27 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:12:27 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

t_bool	is_slice_or_free(const t_meta slice)
{
	if (slice.type == SLICE || slice.type == FREE)
		return (TRUE);
	return (FALSE);
}
