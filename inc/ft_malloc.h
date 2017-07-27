#ifndef FT_MALLOC_H

# define FT_MALLOC_H

#include <stddef.h>

typedef enum e_type
{
    MEM,
    PLAGE,
    NEXT
}       t_type;  

typedef struct s_meta
{
    t_type      type;
    void        *ptr;
    size_t      size;
}       t_meta;

extern t_meta meta_data;

#endif