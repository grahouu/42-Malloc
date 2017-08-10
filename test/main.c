#include "ft_malloc.h"

int					main(void)
{
	void	*m1 = ft_malloc(255);
	ft_malloc(53);
	ft_malloc(96);
	for (int i = 0; i < 200; ++i)
		ft_malloc(50);
	ft_free(m1);
	print_mem_meta_data();
	return (0);
}