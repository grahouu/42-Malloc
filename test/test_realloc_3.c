#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>

/*
* reallocate large ranges
*/
int					main(void)
{
	char *s;
	t_meta *md;

	for (int i = 0; i < 100; ++i)
	{
		s = ft_malloc(SMALL_SIZE + 1);
		if (!s)
		{
			printf("[\x1b[33m TERR \x1b[0m] %s\n", "reallocate large ranges: malloc returned null");
			return (0);
		}
		s = ft_realloc(s, SMALL_SIZE + 500);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate large ranges: realloc returned null");
			return (0);
		}
	}

	md = (t_meta *)g_mem_meta_data.ptr;
	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type != LRANGE && md[i].type != SLICE && md[i].type != NONE && md[i].type != FREE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate large ranges: bad meta datas");
			return (0);
		}
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "reallocate large ranges");
	return (0);
}
