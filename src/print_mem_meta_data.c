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
void                print_mem_meta_data_range(t_meta next)
{
    t_meta *it;
    size_t i;

    i = 0;
    it = (t_meta*)next.ptr;
    while(i < next.size / sizeof(t_meta))
    {
        printf("%-4zu %-5s %-11p %zu\n", i, type_to_str(it[i].type), it[i].ptr, it[i].size);//
        ++i;
    }
    if (it[i - 1].type == NEXT)
        print_mem_meta_data_range(it[i - 1]);
}

void                print_mem_meta_data(void)
{
    printf("%-4s %-5s %-11p %zu\n", "init", type_to_str(mem_meta_data.type), mem_meta_data.ptr, mem_meta_data.size);
    print_mem_meta_data_range(mem_meta_data);
}
// ---