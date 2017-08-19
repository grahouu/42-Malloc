#include "ft_malloc_private.h"

void	ft_free(void *ptr)
{
	t_meta	*slice;

	pthread_mutex_lock(&g_mutex);
	slice = find_meta_data_by_ptr(ptr, SLICE);
	if (slice)
		free_slice(slice);
	merge_freed();
	pthread_mutex_unlock(&g_mutex);
}

void	free(void *ptr)
{
	ft_free(ptr);
}
