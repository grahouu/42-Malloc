#include "ft_malloc_private.h"

t_meta	*find_range_by_meta(const t_meta meta)
{
	size_t  i;
	size_t  end_ptr;
	t_meta  *it;

	it = (t_meta*)mem_meta_data.ptr;
	i = 0;
	while (i < mem_meta_data.size / sizeof(t_meta))
	{
		if (is_range(it[i]))
		{
			end_ptr = (size_t)(it[i].ptr + it[i].size);
			if (meta.ptr >= it[i].ptr && (size_t)meta.ptr < end_ptr)
				return &it[i];
		}
		++i;
	}
	return (NULL);
}
