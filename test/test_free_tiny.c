/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_free_tiny.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:13:06 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:13:06 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>
#include <stdio.h>

/*
* Free all Tiny
*/
int					main(void)
{
	char *prt_malloc;
	t_meta *md;
	size_t count = 200;
	size_t count_ranges = 0;
	size_t count_none = 0;

	for (size_t i = 0; i <= count; ++i)
	{
		prt_malloc = ft_malloc(TINY_SIZE);
		if (!prt_malloc)
		{
			printf("[\x1b[31m TERR \x1b[0m] %s\n", "Meta datas creation: malloc returned null");
			return (0);
		}
	}

	md = (t_meta *)g_mem_meta_data.ptr;
	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		ft_free(md[i].ptr);
	}

	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type == TRANGE)
			count_ranges++;
		else if (md[i].type == NONE)
			count_none++;
	}

	if (count_ranges == 1 && count_none == (g_mem_meta_data.size / sizeof(t_meta) - 1))
		printf("[\x1b[32m OK \x1b[0m]   %s\n", "Free Tiny");
	else{
		printf("[\x1b[31m FAIL \x1b[0m] %s %zu %s %zu %s %zu\n", "Free Tiny - Count range:", count_ranges, " expected:1 Count none:", count_none, " expected:", (g_mem_meta_data.size / sizeof(t_meta) - 1));
		//show_alloc_mem(0);
	}
	return (0);
}
