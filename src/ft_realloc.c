#include "ft_malloc_private.h"

static  void    *ft_memcpy(void *src, void *dst, size_t const size)
{
    unsigned char   *s_it;
    unsigned char   *d_it;
    size_t          i;

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

void    *ft_realloc(void *ptr, size_t const size)
{
    t_meta  *slice;
    t_meta  *freed;
    size_t  needed_size;
    
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
    // call a free slice -->
    slice->type = FREE;
    // <--
    slice = new_slice(size);
    slice->ptr = ft_memcpy(ptr, slice->ptr, size - needed_size);
    return (slice->ptr);
}