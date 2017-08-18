#ifndef FT_MALLOC_H

# define FT_MALLOC_H
# include <unistd.h>

void	*ft_malloc(const size_t size);
void    *ft_free(void *ptr);
void	*ft_realloc(void *ptr, size_t const size);
void	show_alloc_mem();
#endif
