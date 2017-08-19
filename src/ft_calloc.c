#include "ft_malloc_private.h"

static void	ft_memset(unsigned char *mem, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		mem[i] = 0;
		++i;
	}
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = ft_malloc(nmemb * size);
	if (ptr)
		ft_memset(ptr, nmemb * size);
	return (ptr);
}

void		*calloc(size_t nmemb, size_t size)
{
	return (ft_calloc(nmemb, size));
}
