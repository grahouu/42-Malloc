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

t_bool is_slice_in_range(const t_meta slice, const t_meta range)
{
    if (slice.ptr >= range.ptr && slice.ptr < range.ptr + range.size)
        return (TRUE);
    return (FALSE);
}

t_bool is_slice(const t_meta slice)
{
    if (slice.type == SLICE || slice.type == FREE)
        return (TRUE);
    return (FALSE);
}

t_bool  is_range_has_place(const t_meta range, size_t size)
{
    size_t  empty_mem;
    size_t i;
    t_meta *it;

    empty_mem = range.size;
    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (is_slice(it[i]) && is_slice_in_range(it[i], range))
            empty_mem -= it[i].size;
        ++i;
    }
    if (empty_mem >= size)
        return (TRUE);
    return (FALSE);
}

t_meta  *find_range_by_needed_size(size_t size)
{
    size_t i;
    t_meta *it;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].type == RANGE && it[i].size > size && is_range_has_place(it[i], size))
            return (&(it[i]));
        ++i;
    }
    return (NULL);
}

void    *find_empty_mem_in_range(const t_meta range)
{
    size_t  i;
    t_meta  *it;
    void    *ptr;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    ptr = range.ptr;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (is_slice(it[i]) && is_slice_in_range(it[i], range))
            ptr += it[i].size; // pas ouf dans l'idee mais ca marche
        ++i;
    }
    return (ptr);
}

void    *new_memory_slice(size_t size)
{
    t_meta *range;
    t_meta *slice;

    range = find_range_by_needed_size(size);
    if (!range)
    {
        range = find_first_none_meta_data();
        *range = new_memory_range(size);
    }
    slice = find_first_none_meta_data();
    slice->type = SLICE;
    slice->ptr = find_empty_mem_in_range(*range); // <-- not opti
    slice->size = size;
    return(slice->ptr);
}

void    *ft_malloc(size_t size)
{
    if (mem_meta_data.type == NONE)
        mem_meta_data = new_memory_meta_range();
    return (new_memory_slice(size));
}