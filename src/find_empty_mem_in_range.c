#include "ft_malloc_private.h"

void	*find_empty_mem_in_range(const t_meta range, size_t size)
{
	size_t	i;
	size_t	empty_mem;
	t_meta	*it;
	void	*ptr;

	it = (t_meta*)mem_meta_data.ptr;
	i = 0;
	ptr = range.ptr;
	empty_mem = range.size;
	while (i < mem_meta_data.size / sizeof(t_meta))
	{
		if (is_slice_or_free(it[i]) && is_slice_in_range(it[i], range))
		{
			ptr += it[i].size;
			empty_mem -= it[i].size;
		}
		++i;
	}
	if (empty_mem >= size)
		return (ptr);
	return (NULL);
}
