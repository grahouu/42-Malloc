#include "ft_malloc_private.h"

static t_meta  *find_meta_data_in_meta_range_by_ptr(t_meta meta_range, void *ptr)
{
    size_t i;
    t_meta *it;

    it = (t_meta*)meta_range.ptr;
    i = 0;
    while (i < meta_range.size / sizeof(t_meta) - 1)
    {
        if (it[i].ptr == ptr && it[i].type == SLICE)
            return (&(it[i]));
        ++i;
    }
    if (it[i].type == NONE)
        return (NULL);
    return (find_meta_data_in_meta_range_by_ptr(it[i], ptr));
}

t_meta  *find_meta_data_by_ptr(void *ptr)
{
    return (find_meta_data_in_meta_range_by_ptr(mem_meta_data, ptr));
}