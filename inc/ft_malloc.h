#ifndef FT_MALLOC_H

# define FT_MALLOC_H

#include <unistd.h>
void    *ft_malloc(const size_t size);
void    *ft_free(void *ptr);
void    print_mem_meta_data(void);
#endif