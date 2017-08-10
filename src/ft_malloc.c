#include "ft_malloc_private.h"

t_meta mem_meta_data = {.type = NONE, .ptr = NULL, .size = 0};

static void  *find_mem_by_needed_size(const size_t size)
{
    size_t  i;
    t_meta  *it;
    void    *ptr;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].type == FREE && it[i].size >= size)
            return (truncate_freed_memory(&(it[i]), size));
        if (it[i].type == RANGE && it[i].size > size 
            && (ptr = find_empty_mem_in_range(it[i], size)))
            return (ptr);
        ++i;
    }
    return (NULL);
}

static void    *new_memory_slice(const size_t size)
{
    t_meta *range;
    t_meta *slice;

    slice = find_first_none_meta_data();
    slice->ptr = find_mem_by_needed_size(size);
    slice->type = SLICE;
    slice->size = size;
    if (!slice->ptr)
    {
        range = find_first_none_meta_data();
        *range = new_memory_range(size);
        slice->ptr = range->ptr;
    }
    return(slice->ptr);
}

void    *ft_malloc(const size_t size)
{
    if (mem_meta_data.type == NONE)
        mem_meta_data = new_meta_range();
    return (new_memory_slice(size));
}