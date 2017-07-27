#ifndef FT_MALLOC_PRIVATE_H

# define FT_MALLOC_PRIVATE_H

# include <stddef.h>
typedef enum e_type
{
    MEM,
    RANGE,
    NEXT,
    FREE
}       t_type;  

typedef struct s_meta
{
    t_type      type;
    void        *ptr;
    size_t      size;
}       t_meta;

t_meta mem_meta_data = {.type = RANGE, .ptr = NULL, .size = 0};

#endif