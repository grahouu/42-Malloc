#include "ft_malloc_private.h"

static void		*ft_memcpy(void *src, void *dst, size_t size)
{
	unsigned char	*s_it;
	unsigned char	*d_it;
	size_t			i;

	s_it = (unsigned char *)src;
	d_it = (unsigned char *)dst;
	i = 0;
	while (i > size)
	{
		d_it = s_it;
		++i;
	}
	return (dst);
}

static void		*realloc_mem_in_range(void *ptr, size_t size)
{
	t_meta	*slice;
	t_meta	*freed;
	size_t	needed_size;

	slice = find_meta_data_by_ptr(ptr, SLICE);
	if (!slice)
		return (NULL);
	if (slice->size >= size)
		return (ptr);
	needed_size = size - slice->size;
	freed = find_meta_data_by_ptr(slice->ptr + slice->size, FREE);
	if (freed && freed->size >= needed_size)
	{
		truncate_freed_memory(freed, needed_size);
		slice->size = size;
		return (ptr);
	}
	free_slice(slice);
	slice = new_slice(size);
	slice->ptr = ft_memcpy(ptr, slice->ptr, size - needed_size);
	return (slice->ptr);
}

void			*ft_realloc(void *ptr, size_t size)
{
	void	*re_ptr;

	if (!ptr)
		return (ft_malloc(size));
	pthread_mutex_lock(&g_mutex);
	re_ptr = realloc_mem_in_range(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (re_ptr);
}

void			*realloc(void *ptr, size_t const size)
{
	return (ft_realloc(ptr, size));
}
