#include "ft_malloc_private.h"

t_bool	is_range_empty(t_meta range)
{
	size_t	i;
	size_t	end_ptr;
	t_meta	*it;

	it = (t_meta*)g_mem_meta_data.ptr;
	end_ptr = (size_t)(range.ptr + range.size);
	i = 0;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (it[i].type == SLICE && is_slice_in_range(it[i], range))
			return (FALSE);
		++i;
	}
	return (TRUE);
}
