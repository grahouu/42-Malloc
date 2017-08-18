/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:13:26 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:13:26 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>
#include <stdio.h>

/*
* Allocate large ranges
*/
int					main(void)
{
	char *s;
	t_meta *md;

	for (int i = 0; i < 100; ++i)
	{
		s = ft_malloc(SMALL_SIZE + 10);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "Allocate large ranges: malloc returned null");
			return (0);
		}
	}

	md = (t_meta *)g_mem_meta_data.ptr;
	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type != LRANGE && md[i].type != SLICE && md[i].type != NONE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "Allocate large ranges: bad meta datas");
			return (0);
		}
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "Allocate large ranges");
	return (0);
}
