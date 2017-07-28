#include "ft_malloc.h"

int					main(void)
{
	ft_malloc(255);
	ft_malloc(53);
	ft_malloc(96);
	print_mem_meta_data();
	return (0);
}