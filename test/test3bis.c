#include <strings.h>
#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>
#include <stdio.h>

#define M (1024 * 1024)

void		print(char *s)
{
	write(1, s, strlen(s));
}

int			main(void)
{
	char	*addr1;
	char	*addr2;
	char	*addr3;

	addr1 = (char*)ft_malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	if (strcmp(addr1, "Bonjours\n"))
	{
		printf("[\x1b[31m FAIL \x1b[0m] %s\n", "malloc fill and realloc bis: strcpy bad copy");
		return (0);
	}
	addr2 = (char*)ft_malloc(16 * M);
	addr3 = (char*)ft_realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	if (strcmp(addr3, "Bonjours\n"))
	{
		printf("[\x1b[31m FAIL \x1b[0m] %s\n", "malloc fill and realloc bis: realloc bad copy");
		return (0);
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "malloc fill and realloc bis");
	return (0);
}
