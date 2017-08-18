#ifndef FT_MALLOC_H

# define FT_MALLOC_H
# include <unistd.h>

void	*malloc(const size_t size);
void	free(void *ptr);
void	*realloc(void *ptr, size_t const size);
void	show_alloc_mem();
#endif
