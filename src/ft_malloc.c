#include "ft_malloc_private.h"

t_meta mem_meta_data = {.type = NONE, .ptr = NULL, .size = 0};

void	*ft_malloc(const size_t size)
{
	if (mem_meta_data.type == NONE)
		mem_meta_data = new_meta_range();
	return (new_slice(size)->ptr);
}
