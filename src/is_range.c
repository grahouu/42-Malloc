#include "ft_malloc_private.h"

t_bool	is_range(const t_meta range)
{
	if (range.type == TRANGE 
		|| range.type == SRANGE 
		|| range.type == LRANGE)
		return (TRUE);
	return (FALSE);
}
