#include "ft_malloc_private.h"
#include <stdio.h> //norme

static const char    *type_to_str(t_type t)
{
    if (t == SLICE)
        return ("SLICE");
    else if (t == RANGE)
        return ("RANGE");
    else if (t == NEXT)
        return ("NEXT");
    else if (t == FREE)
        return ("FREE");
    return ("NONE");
}

// norme !!
void                print_mem_meta_data(void)
{
    printf("%-4s %-5s %-11p %zu\n", "init", type_to_str(mem_meta_data.type), mem_meta_data.ptr, mem_meta_data.size);
    t_meta *it;

    it = (t_meta*)mem_meta_data.ptr;
    for(size_t i = 0; i < mem_meta_data.size / sizeof(t_meta); ++i)
    {
        printf("%-4zu %-5s %-11p %zu\n", i, type_to_str(it[i].type), it[i].ptr, it[i].size);//
    }
}
// ---