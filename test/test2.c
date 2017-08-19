#include "ft_malloc_private.h"
#include <stdio.h>

int main (void)
{
	char	*str;

	for (int i = 0; i < 1024; ++i)
	{
		str = ft_malloc(1024);
		ft_free(str);
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "malloc and free");
	return (0);
}
