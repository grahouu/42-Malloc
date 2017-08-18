/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_meta_data_by_ptr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:11:50 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:11:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

t_meta	*find_meta_data_by_ptr(void *ptr, t_type meta_type)
{
	size_t i;
	t_meta *it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (it[i].ptr == ptr && it[i].type == meta_type)
			return (&(it[i]));
		++i;
	}
	return (NULL);
}
