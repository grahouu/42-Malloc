#ifndef FT_MALLOC_H

# define FT_MALLOC_H

void	*ft_malloc(const size_t size);
void    *ft_free(void *ptr);
void	*ft_realloc(void *ptr, size_t const size);
void	print_mem_meta_data(size_t counter);
#endif
