#include "ft_malloc_private.h"
#include <unistd.h>

static unsigned long		ft_d_size(unsigned long n, unsigned long base)
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

void	ft_putstr_padded(char const *s, size_t padding)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		++n;
    write(1, s, n);
    write(1, "                         ", padding - n);
    
}

void ft_putnbr_padded(unsigned long n, unsigned long padding, unsigned long base)
{
	char		str[20];
	const char		*bstr = "0123456789abcdef";
	unsigned long	d_size;
    unsigned long  i;

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

void                print_one_meta_data(t_meta md)
{
    ft_putstr_padded(type_to_str(md.type), 6);
    if (md.ptr)
    {
        write(1, "0x", 2);
        ft_putnbr_padded((unsigned long)md.ptr, 10, 16);
    }
    else
        ft_putstr_padded("NULL", 12);
    ft_putnbr_padded((unsigned long)md.size, 0, 10);
    write(1, "\n", 1);
}

void                print_mem_meta_data(size_t counter)
{
    t_meta *it;
    size_t i;

    i = 0;
    it = (t_meta*)mem_meta_data.ptr;
    if (counter == 0)
        counter = mem_meta_data.size / sizeof(t_meta);
    print_one_meta_data(mem_meta_data);
    while(i < counter)
    {
        print_one_meta_data(it[i]);
        ++i;
    }
    write(1, "\n", 1);
}