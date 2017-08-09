#include "ft_malloc_private.h"
#include <sys/mman.h>

t_meta  new_memory_range(size_t size)
{
    const size_t    page_size = getpagesize();
    t_meta          memory_range;
    size_t          memory_size;

    if (size % page_size)
        memory_size = (size / page_size + 1) * page_size;
    else
        memory_size = size;
    
    memory_range.type = RANGE;
    memory_range.ptr = mmap(0, memory_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    memory_range.size = memory_size;
    return (memory_range);
}

t_meta  new_meta_range(void)
{
    t_meta new;
    
    new = new_memory_range(1);
    new.type = NEXT;
    return (new);
}
