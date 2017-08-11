#include "ft_malloc_private.h"

<<<<<<< HEAD
static t_meta  *find_meta_data_in_meta_range_by_ptr(t_meta meta_range, void *ptr, t_type meta_type)
=======
t_meta  *find_meta_data_by_ptr(void *ptr, t_type meta_type)
>>>>>>> master
{
    size_t i;
    t_meta *it;

    it = (t_meta*)mem_meta_data.ptr;
    i = 0;
    while (i < mem_meta_data.size / sizeof(t_meta) - 1)
    {
        if (it[i].ptr == ptr && it[i].type == meta_type)
            return (&(it[i]));
        ++i;
    }
<<<<<<< HEAD
    if (it[i].type == NONE)
        return (NULL);
    return (find_meta_data_in_meta_range_by_ptr(it[i], ptr, meta_type));
}

t_meta  *find_meta_data_by_ptr(void *ptr, t_type meta_type)
{
    return (find_meta_data_in_meta_range_by_ptr(mem_meta_data, ptr, meta_type));
=======
    return (NULL);
>>>>>>> master
}