#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>

/*
* Allocate large ranges
*/
int					main(void)
{
	char *s;
	t_meta *md;

	for (int i = 0; i < 100; ++i)
	{
		s = ft_malloc(SMALL_SIZE + 10);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "Allocate large ranges: malloc returned null");
			return (1);
		}
	}

	md = (t_meta *)mem_meta_data.ptr;
	for (size_t i = 0; i < mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type != LRANGE && md[i].type != SLICE && md[i].type != NONE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "Allocate large ranges: bad meta datas");
			return (1);
		}
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "Allocate large ranges");
	return (0);
}