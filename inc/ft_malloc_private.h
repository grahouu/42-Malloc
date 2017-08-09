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

typedef enum e_bool
{
    FALSE = 0,
    TRUE = 1
}   t_bool;

typedef struct s_meta
{
    t_type      type;
    void        *ptr;
    size_t      size;
}       t_meta;

extern t_meta mem_meta_data;

t_meta  new_memory_range(size_t size);
t_meta  new_meta_range(void);
t_meta  *find_first_none_meta_data(void);
t_bool  is_slice_in_range(const t_meta slice, const t_meta range);
void    *find_empty_mem_in_range(const t_meta range, size_t size);
t_bool  is_slice_or_free(const t_meta slice);
#endif