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

void        print_meta(t_meta meta)
{
    printf("%-5s %-11p %zu\n", type_to_str(meta.type), meta.ptr, meta.size);//
}
