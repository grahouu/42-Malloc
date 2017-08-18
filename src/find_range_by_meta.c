/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_range_by_meta.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:11:53 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:11:54 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

t_meta	*find_range_by_meta(const t_meta meta)
{
	size_t	i;
	size_t	end_ptr;
	t_meta	*it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (is_range(it[i]))
		{
			end_ptr = (size_t)(it[i].ptr + it[i].size);
			if (meta.ptr >= it[i].ptr && (size_t)meta.ptr < end_ptr)
				return (&it[i]);
		}
		++i;
	}
	return (NULL);
}
