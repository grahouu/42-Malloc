#include "ft_malloc_private.h"

const char	*type_to_str(t_type t)
{
	if (t == SLICE)
		return ("SLICE");
	else if (t == TRANGE)
		return ("TINY");
	else if (t == SRANGE)
		return ("SMALL");
	else if (t == LRANGE)
		return ("LARGE");
	else if (t == NEXT)
		return ("NEXT");
	else if (t == FREE)
		return ("FREE");
	return ("NONE");
}
