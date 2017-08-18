#include "ft_malloc_private.h"

t_meta	*find_meta_data_by_ptr(void *ptr, t_type meta_type)
{
	size_t i;
	t_meta *it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 0;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (it[i].ptr == ptr && it[i].type == meta_type)
			return (&(it[i]));
		++i;
	}
	return (NULL);
}
