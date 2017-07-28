#include "ft_malloc_private.h"
#include <sys/mman.h>

t_meta mem_meta_data = {.type = NONE, .ptr = NULL, .size = 0};

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

t_meta  new_memory_meta_range(void)
{
    t_meta new;
    
    new = new_memory_range(1);
    new.type = NEXT;
    return (new);
}

t_meta  *find_first_none_meta_data(void)
{
    size_t i;
    t_meta *it;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].type == NONE)
            return (&(it[i]));
        ++i;
    }
    return (NULL);
}

void    *new_memory_slice(size_t size)
{
    t_meta *range;
    t_meta *slice;

    range = find_first_none_meta_data();
    *range = new_memory_range(size);
    slice = find_first_none_meta_data();
    slice->type = SLICE;
    slice->ptr = range->ptr; // <-- not opti
    slice->size = size;
    return(slice->ptr);
}

void    *ft_malloc(size_t size)
{
    if (mem_meta_data.type == NONE)
        mem_meta_data = new_memory_meta_range();
    return (new_memory_slice(size));
}