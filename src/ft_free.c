#include "ft_malloc_private.h"

void    ft_free(void *ptr)
{
    t_meta      *slice;
    t_meta      *range;
    size_t      if_empty;

    slice = find_meta_data_by_ptr(ptr, SLICE);
    if (!slice)
        return;
    slice->type = FREE;
    range = find_range_by_meta(*slice);
    if (range){
        if_empty = check_if_empty_range(*range);
        if (if_empty)
            del_memory_range(range);
    }
}