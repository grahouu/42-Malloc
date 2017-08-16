#include "ft_malloc_private.h"
#include <unistd.h>

size_t    count_type(const t_type type)
{
    size_t  i;
    size_t  count;
    t_meta  *it;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    count = 0;
    while (i < mem_meta_data.size / sizeof(t_meta))
    {
        if (it[i].type == type)
            count++;
        ++i;
    }
    return (count);
}