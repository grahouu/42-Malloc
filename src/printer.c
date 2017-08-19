/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 01:48:28 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/20 01:52:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_private.h"

static unsigned long	ft_d_size(unsigned long n, unsigned long base)
{
	unsigned long			d_size;

	d_size = 1;
	while (n / base >= 1)
	{
		n = n / base;
		d_size = d_size * base;
	}
	return (d_size);
}

void					ft_putstr_padded(char const *s, size_t padding)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		++n;
	write(1, s, n);
	write(1, "                         ", padding - n);
}

void					ft_putnbr_padded(unsigned long n,
							unsigned long padding, unsigned long base)
{
	char			str[20];
	const char		*bstr = "0123456789abcdef";
	unsigned long	d_size;
	unsigned long	i;

	i = 0;
	d_size = ft_d_size(n, base);
	while (d_size > 0)
	{
		str[i] = bstr[(n / d_size)];
		n = n % d_size;
		d_size = d_size / base;
		i++;
	}
	str[i] = '\0';
	ft_putstr_padded(str, padding);
}
