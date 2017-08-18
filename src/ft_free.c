#include "ft_malloc_private.h"

void	ft_free(void *ptr)
{
	t_meta	*slice;

	slice = find_meta_data_by_ptr(ptr, SLICE);
	if (slice)
		free_slice(slice);
	merge_freed();
}

void	free(void *ptr)
{
	ft_free(ptr);
}
