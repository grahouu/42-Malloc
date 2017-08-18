/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:13:45 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:27:18 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>
#include <stdio.h>

/*
* reallocate tiny to small ranges
*/
int					main(void)
{
	char *s;
	t_meta *md;

	for (int i = 0; i < 100; ++i)
	{
		s = ft_malloc(TINY_SIZE);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate tiny to small ranges: malloc returned null");
			return (0);
		}
		s = ft_realloc(s, SMALL_SIZE);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate tiny to small ranges: realloc returned null");
			return (0);
		}
	}

	md = (t_meta *)g_mem_meta_data.ptr;
	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type == LRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate tiny to small ranges: large range in meta datas");
			show_alloc_mem(110);
			return (0);
		}
		if (md[i].type == SLICE && md[i].size > TINY_SIZE && find_range_by_meta(md[i])->type == TRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate tiny to small ranges: small slice in tiny range");
			show_alloc_mem(110);
			return (0);
		}
		if (md[i].type == SLICE && md[i].size <= TINY_SIZE && find_range_by_meta(md[i])->type == SRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate tiny to small ranges: tiny slice in small range");
			show_alloc_mem(110);
			return (0);
		}
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "reallocate tiny to small ranges");
	return (0);
}
