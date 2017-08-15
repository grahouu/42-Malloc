#include "ft_malloc_private.h"
#include <stdio.h> //norme

static const char    *type_to_str(t_type t)
{
    if (t == SLICE)
        return ("SLICE");
    else if (t == TRANGE)
        return ("TINY");
    else if (t == SRANGE)
        return ("SMALL");
    else if (t == LRANGE)
        return ("LARGE");
    else if (t == NEXT)
        return ("NEXT");
    else if (t == FREE)
        return ("FREE");
    return ("NONE");
}

void                print_mem_meta_data(size_t counter)
{
    printf("%-4s %-5s %-11p %zu\n", "init", type_to_str(mem_meta_data.type), mem_meta_data.ptr, mem_meta_data.size);
    t_meta *it;
    size_t i;

    i = 0;
    it = (t_meta*)mem_meta_data.ptr;
    if (counter == 0)
        counter = mem_meta_data.size / sizeof(t_meta);
    while(i < counter)
    {
        printf("%-4zu %-5s %-11p %zu\n", i, type_to_str(it[i].type), it[i].ptr, it[i].size);//
        ++i;
    }
    write(1, "\n", 1);
}