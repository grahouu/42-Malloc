#ifndef FT_MALLOC_PRIVATE_H

# define FT_MALLOC_PRIVATE_H

#include <unistd.h>
# include <stddef.h>
#include <stdio.h> //norme
typedef enum e_type
{
    NONE,
    SLICE,
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

extern t_meta mem_meta_data;
void                print_mem_meta_data(void);
#endif