#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>

/*
* reallocate small to large ranges
*/
int					main(void)
{
	char *s;
	t_meta *md;

	for (int i = 0; i < 100; ++i)
	{
		s = ft_malloc(SMALL_SIZE);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: malloc returned null");
			return (0);
		}
		s = ft_realloc(s, SMALL_SIZE + 100);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: realloc returned null");
			return (0);
		}
	}

	md = (t_meta *)g_mem_meta_data.ptr;
	for (size_t i = 0; i < g_mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type == TRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: tiny range in meta datas");
			print_one_meta_data(md[i]);
			return (0);
		}
		if (md[i].type == SLICE && md[i].size > SMALL_SIZE && find_range_by_meta(md[i])->type == SRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: large slice in small range");
			print_one_meta_data(md[i]);
			print_one_meta_data(*find_range_by_meta(md[i]));
			return (0);
		}
		if (md[i].type == SLICE && md[i].size <= SMALL_SIZE && find_range_by_meta(md[i])->type == LRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: small slice in large range");
			print_one_meta_data(md[i]);
			print_one_meta_data(*find_range_by_meta(md[i]));
			return (0);
		}
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "reallocate small to large ranges");
	return (0);
}
