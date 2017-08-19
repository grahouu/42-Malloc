#include "ft_malloc_private.h"
#include <stdio.h>

int			main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)ft_malloc(1024);
		addr[0] = 42;
		i++;
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "malloc");
	return (0);
}
