#include "ft_malloc_private.h"

static void		merge(t_meta *first, t_meta *second)
{
	first->size += second->size;
	second->type = NONE;
}

static void		find_next(t_meta *freed)
{
	size_t	i;
	t_meta	*it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (it[i].type == FREE && it[i].ptr == freed->ptr + freed->size)
		{
			merge(freed, &(it[i]));
			return (find_next(&(it[i])));
		}
		++i;
	}
}

void			merge_freed(void)
{
	size_t	i;
	t_meta	*it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (it[i].type == FREE)
			find_next(&(it[i]));
		++i;
	}
}
