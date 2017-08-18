/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:12:12 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:12:12 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

t_meta g_mem_meta_data = {.type = NONE, .ptr = NULL, .size = 0};
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*ft_malloc(size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_mutex);
	if (g_mem_meta_data.type == NONE)
		g_mem_meta_data = new_meta_range();
	ptr = new_slice(size)->ptr;
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}

void	*malloc(size_t size)
{
	return (ft_malloc(size));
}
