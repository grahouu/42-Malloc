#include "ft_malloc_private.h"

t_bool  is_range_empty(t_meta range)
{
    size_t  i;
    size_t  end_ptr;
    t_meta  *it;

    it = (t_meta*)mem_meta_data.ptr;
    end_ptr = (size_t)(range.ptr + range.size);
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].type == SLICE && it[i].ptr >= range.ptr && (size_t)it[i].ptr <= end_ptr)
            return (FALSE);
        ++i;
    }
    return (TRUE);
}