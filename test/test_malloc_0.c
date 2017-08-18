/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:13:09 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:13:09 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <stdio.h>

/*
* Meta datas creation
*/
int					main(void)
{
	char *s;
	t_meta *md;
	size_t n;

	for (int i = 0; i < 3000; ++i)
	{
		s = ft_malloc(1);
		if (!s)
		{
			printf("[\x1b[31m TERR \x1b[0m] %s\n", "Meta datas creation: malloc returned null");
			return (0);
		}
	}

	md = (t_meta *)g_mem_meta_data.ptr;
	n = 0;
	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type == SLICE)
			++n;
	}
	if (n == 3000)
		printf("[\x1b[32m OK \x1b[0m]   %s\n", "Meta datas creation");
	else
		printf("[\x1b[31m FAIL \x1b[0m] %s %zu %s\n", "Slices creation:", n, "created 3000 expected");
	return (0);
}
