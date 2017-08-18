/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_free_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:12:54 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:12:54 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** Free all Tiny
*/
int	main(void)
{
	char *prt_malloc;
	t_meta *md;
	size_t count = 10;
	size_t count_ranges = 0;
	size_t count_none = 0;
	const int MAX = 2, MIN = 0;
	int     	random;

	for (size_t i = 0; i <= count; ++i)
	{
		random = (rand() % (MAX - MIN + 1)) + MIN;
		if (random == 0)
			prt_malloc = ft_malloc(TINY_SIZE);
		else if (random == 1)
			prt_malloc = ft_malloc(SMALL_SIZE);
		else
			prt_malloc = ft_malloc(SMALL_SIZE + 20);

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
		if (is_range(md[i]))
			count_ranges++;
		else if (md[i].type == NONE)
			count_none++;
	}

	// show_alloc_mem(0);

	if (count_ranges == 3 && count_none == (g_mem_meta_data.size / sizeof(t_meta) - 3))
		printf("[\x1b[32m OK \x1b[0m]   %s\n", "Free All random");
	else{
		printf("[\x1b[31m FAIL \x1b[0m] %s %zu %s %zu %s %zu\n", "Free All random - Count range:", count_ranges, " expected:3 Count none:", count_none, " expected:", (g_mem_meta_data.size / sizeof(t_meta) - 3));
		//show_alloc_mem(0);
	}
	return (0);
}
