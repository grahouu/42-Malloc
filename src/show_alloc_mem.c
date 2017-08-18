/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 17:42:11 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 17:42:13 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

static size_t	used_mem(t_meta range)
{
	size_t	i;
	size_t	used_mem;
	t_meta	*it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	used_mem = 0;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (it[i].type == SLICE && is_slice_in_range(it[i], range))
			used_mem += it[i].size;
		++i;
	}
	return (used_mem * 100 / range.size);
}

static void		print_prefix(t_meta md)
{
	if (is_range(md))
		write(1, "\x1B[36m", 5);
	if (md.type == FREE)
		write(1, "\x1B[35m", 5);
	if (md.type == NONE)
		write(1, "\x1B[32m", 5);
	if (md.type != SLICE)
		ft_putstr_padded(type_to_str(md.type), 6);
	else
		write(1, "      ", 6);
}

void			print_one_meta_data(t_meta md)
{
	print_prefix(md);
	if (md.ptr)
	{
		write(1, "0x", 2);
		ft_putnbr_padded((unsigned long)md.ptr, 10, 16);
		ft_putstr_padded("- 0x", 0);
		ft_putnbr_padded((unsigned long)md.ptr + md.size, 10, 16);
	}
	else
		ft_putstr_padded("NULL", 26);
	ft_putstr_padded(":", 2);
	ft_putnbr_padded((unsigned long)md.size, 0, 10);
	write(1, " octets", 7);
	if (is_range(md))
	{
		write(1, ", ", 2);
		ft_putnbr_padded((unsigned long)used_mem(md), 0, 10);
		ft_putstr_padded("% used", 0);
	}
	write(1, "\033[0m\n", 5);
}

void			show_alloc_mem(void)
{
	t_meta	*it;
	size_t	i;

	sort_meta_data();
	i = 0;
	it = (t_meta*)g_mem_meta_data.ptr;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (it[i].type != NONE)
			print_one_meta_data(it[i]);
		++i;
	}
	write(1, "\n", 1);
}
