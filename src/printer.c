#include "ft_malloc_private.h"
#include <stdio.h> //norme

void        print_meta(t_meta meta)
{
    printf("%-5s %-11p %zu\n", type_to_str(meta.type), meta.ptr, meta.size);//
}
