#include "ft_malloc_private.h"
#include <sys/mman.h>

static t_meta	new_range(size_t size)
{
	t_meta			memory_range;

	memory_range.ptr = mmap(0, size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	memory_range.size = size;
	return (memory_range);
}

t_meta			new_memory_range(size_t size)
{
	t_meta			new;
	t_type			type;
	size_t			memory_size;
	const size_t	page_size = (size_t)getpagesize();

	type = LRANGE;
	if (size <= TINY_SIZE)
	{
		memory_size = TINY_NB_PAGES * (size_t)getpagesize();
		type = TRANGE;
	}
	else if (size <= SMALL_SIZE)
	{
		memory_size = SMALL_NB_PAGES * (size_t)getpagesize();
		type = SRANGE;
	}
	else if (size % page_size)
		memory_size = (size / page_size + 1) * page_size;
	else
		memory_size = size;
	new = new_range(memory_size);
	new.type = type;
	return (new);
}

t_meta			new_meta_range(void)
{
	t_meta new;

	if (g_mem_meta_data.type == NONE)
		new = new_range((size_t)getpagesize());
	else
		new = new_range(g_mem_meta_data.size + (size_t)getpagesize());
	new.type = NEXT;
	return (new);
}

void			del_memory_range(t_meta *range)
{
	munmap(range->ptr, range->size);
	range->type = NONE;
}
