#include "ft_malloc_private.h"

t_bool is_slice_or_free(const t_meta slice)
{
    if (slice.type == SLICE || slice.type == FREE)
        return (TRUE);
    return (FALSE);
}