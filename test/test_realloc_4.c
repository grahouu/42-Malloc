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
			return (1);
		}
		s = ft_realloc(s, SMALL_SIZE + 100);
		if (!s)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: realloc returned null");
			return (1);
		}
	}

	md = (t_meta *)mem_meta_data.ptr;
	for (size_t i = 0; i < mem_meta_data.size / sizeof(t_meta); ++i)
	{
		if (md[i].type == TRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: tiny range in meta datas");
			print_mem_meta_data(110);
			return (1);
		}
		if (md[i].type == SLICE && md[i].size > SMALL_SIZE && find_range_by_meta(md[i])->type == SRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: large slice in small range");
			print_mem_meta_data(110);
			return (1);
		}
		if (md[i].type == SLICE && md[i].size <= SMALL_SIZE && find_range_by_meta(md[i])->type == LRANGE)
		{
			printf("[\x1b[31m FAIL \x1b[0m] %s\n", "reallocate small to large ranges: small slice in large range");
			print_mem_meta_data(110);
			return (1);
		}
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "reallocate small to large ranges");
	return (0);
}