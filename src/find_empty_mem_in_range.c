/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_empty_mem_in_range.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:11:40 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:11:40 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

void	*find_empty_mem_in_range(const t_meta range, size_t size)
{
	size_t	i;
	size_t	empty_mem;
	t_meta	*it;
	void	*ptr;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	ptr = range.ptr;
	empty_mem = range.size;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (is_slice_or_free(it[i]) && is_slice_in_range(it[i], range))
		{
			ptr += it[i].size;
			empty_mem -= it[i].size;
		}
		++i;
	}
	if (empty_mem >= size)
		return (ptr);
	return (NULL);
}
