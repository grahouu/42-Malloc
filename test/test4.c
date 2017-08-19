#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ft_malloc_private.h"
#include <stdio.h>

void		print(char *s)
{
	write(1, s, strlen(s));
}

int			main(void)
{
	char	*addr;

	addr = ft_malloc(16);
	ft_free(NULL);
	ft_free((void *)addr + 5);
	if (ft_realloc((void *)addr + 5, 10) == NULL)
	{
		printf("[\x1b[32m OK \x1b[0m]   %s\n", "test error case realloc and free");
		return (0);
	}
	printf("[\x1b[31m FAIL \x1b[0m] %s\n", "test error case realloc and free: realloc didn't return NULL");
	return (0);
}
