#include "ft_malloc_private.h"

static t_meta  *find_first_none_meta_data_in_meta_range(t_meta meta_range)
{
    size_t i;
    t_meta *it;

    it = (t_meta*)meta_range.ptr;
    i = 0;
    while (i < meta_range.size / sizeof(t_meta) - 1)
    {
        if (it[i].type == NONE)
            return (&(it[i]));
        ++i;
    }
    if (it[i].type == NONE)
        it[i] = new_meta_range();
    return (find_first_none_meta_data_in_meta_range(it[i]));
}

t_meta  *find_first_none_meta_data(void)
{
    return (find_first_none_meta_data_in_meta_range(mem_meta_data));
}