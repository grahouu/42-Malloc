#include "ft_malloc.h"
#include <unistd.h>

int					main(void)
{
	ft_malloc(5302);
	void	*m1 = ft_malloc(700);
	void	*m2 = ft_malloc(367);
	ft_malloc(53);
	ft_malloc(96);
	ft_malloc(900);
	for (int i = 0; i < 200; ++i)
		ft_malloc(50);
	print_mem_meta_data(10);
	ft_free(m1);
	ft_malloc(255);
	ft_free(m2);
	ft_malloc(255);
	print_mem_meta_data(10);
	return (0);
}