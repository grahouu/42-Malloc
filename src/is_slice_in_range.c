#include "ft_malloc_private.h"

t_bool	is_slice_in_range(const t_meta slice, const t_meta range)
{
	if (slice.ptr >= range.ptr && slice.ptr < range.ptr + range.size)
		return (TRUE);
	return (FALSE);
}
