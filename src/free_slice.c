/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:11:57 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:11:57 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

static void		set_range_slices_to_none(t_meta range)
{
	size_t	i;
	size_t	end_ptr;
	t_meta	*it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	end_ptr = (size_t)(range.ptr + range.size);
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (is_range(it[i]) == FALSE && it[i].ptr >= range.ptr
			&& (size_t)it[i].ptr < end_ptr)
			it[i].type = NONE;
		++i;
	}
}

void			free_slice(t_meta *slice)
{
	t_meta	*range;

	slice->type = FREE;
	range = find_range_by_meta(*slice);
	if (range)
	{
		if (is_range_empty(*range))
		{
			set_range_slices_to_none(*range);
			if (count_type(range->type) > 1)
				del_memory_range(range);
		}
	}
}
