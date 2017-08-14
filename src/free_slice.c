#include "ft_malloc_private.h"

static void set_range_slices_to_none(t_meta range)
{
    size_t  i;
    size_t  end_ptr;
    t_meta  *it;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    end_ptr = (size_t)(range.ptr + range.size);
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].ptr >= range.ptr && (size_t)it[i].ptr < end_ptr)
            it[i].type = NONE;
        ++i;
    }
}

void    free_slice(t_meta *slice)
{
    t_meta      *range;
    size_t      if_empty;

    slice->type = FREE;
    range = find_range_by_meta(*slice);
    printf("%-5s %-11p %zu\n", "START RANGE", range->ptr, range->size);
    printf("%-5s %-11p\n", "END RANGE", range->ptr + range->size);
    if (range)
    {
        if_empty = check_if_empty_range(*range);
        if (if_empty)
        {
            set_range_slices_to_none(*range);
            del_memory_range(range);
        } 
    }
}