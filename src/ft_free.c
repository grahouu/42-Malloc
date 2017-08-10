#include "ft_malloc_private.h"

void    ft_free(void *ptr)
{
    t_meta  *slice = find_meta_data_by_ptr(ptr);
    slice->type = FREE;
}