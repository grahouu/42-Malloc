#include "ft_malloc_private.h"

static t_bool   is_valid_storage(t_meta range, size_t size)
{
    if ((size <= TINY_SIZE && range.type == TRANGE)
        || (size > TINY_SIZE && size <= SMALL_SIZE && range.type == SRANGE)
        || (size > SMALL_SIZE && range.type == LRANGE))
        return (TRUE);
    return (FALSE);
}

static void  *find_mem_by_needed_size(const size_t size)
{
    size_t  i;
    t_meta  *it;
    void    *ptr;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].type == FREE 
            && it[i].size >= size
            && is_valid_storage(*find_range_by_meta(it[i]), size)
            )
            return (truncate_freed_memory(&(it[i]), size));
        if (is_range(it[i]) && it[i].size > size
            && is_valid_storage(it[i], size)
            && (ptr = find_empty_mem_in_range(it[i], size)))
            return (ptr);
        ++i;
    }
    return (NULL);
}

t_meta    *new_slice(const size_t size)
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
    return(slice);
}