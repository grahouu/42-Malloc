#include "ft_malloc_private.h"

static t_meta  *find_meta_data_in_meta_range_by_ptr(t_meta meta_range, void *ptr, t_type meta_type)
{
    size_t i;
    t_meta *it;

    it = (t_meta*)meta_range.ptr;
    i = 0;
    while (i < meta_range.size / sizeof(t_meta) - 1)
    {
        if (it[i].ptr == ptr && it[i].type == meta_type)
            return (&(it[i]));
        ++i;
    }
    if (it[i].type == NONE)
        return (NULL);
    return (find_meta_data_in_meta_range_by_ptr(it[i], ptr, meta_type));
}

t_meta  *find_meta_data_by_ptr(void *ptr, t_type meta_type)
{
    return (find_meta_data_in_meta_range_by_ptr(mem_meta_data, ptr, meta_type));
}