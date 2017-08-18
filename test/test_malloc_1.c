/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:13:12 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:27:18 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <stdio.h>

/*
* Allocate tiny ranges
*/
int					main(void)
{
	char *s;
	t_meta *md;

	for (int i = 0; i < 2000; ++i)
	{
		s = ft_malloc(TINY_SIZE);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "Allocate tiny ranges: malloc returned null");
			return (0);
		}
	}

	md = (t_meta *)g_mem_meta_data.ptr;
	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type != TRANGE && md[i].type != SLICE && md[i].type != NONE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "Allocate tiny ranges: bad meta datas");
			return (0);
		}
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "Allocate tiny ranges");
	return (0);
}
