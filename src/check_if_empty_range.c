#include "ft_malloc_private.h"

size_t  check_if_empty_range(t_meta range)
{
    size_t  i;
    size_t  end_ptr;
    t_meta  *it;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].type == SLICE)
        {
            end_ptr = (size_t)(range.ptr + range.size);
            if (it[i].ptr >= range.ptr && (size_t)it[i].ptr <= end_ptr)
                return (0);
        }
        ++i;
    }
    return (1);
}