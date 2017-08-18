/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate_freed_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:12:45 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:12:46 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

void	*truncate_freed_memory(t_meta *freed, const size_t size)
{
	void	*truncated_memory;

	truncated_memory = freed->ptr;
	freed->size -= size;
	if (freed->size > 0)
	{
		freed->ptr += size;
		return (truncated_memory);
	}
	freed->type = NONE;
	return (truncated_memory);
}
