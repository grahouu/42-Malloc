#include "ft_malloc_private.h"

static t_bool	priority(t_meta last, t_meta curr)
{
	if (last.type == NONE && curr.type != NONE)
		return (TRUE);
	if (last.type != NONE && curr.type == NONE)
		return (FALSE);
	if (last.ptr > curr.ptr)
		return (TRUE);
	if (last.ptr < curr.ptr)
		return (FALSE);
	if (!is_range(last) && is_range(curr))
		return (TRUE);
	return (FALSE);
}

static	void	swap_meta(t_meta *last, t_meta *curr)
{
	t_meta tmp;

	tmp = *last;
	*last = *curr;
	*curr = tmp;
}

void			sort_meta_data(void)
{
	size_t	i;
	t_meta	*it;

	it = (t_meta*)g_mem_meta_data.ptr;
	i = 1;
	while (i < g_mem_meta_data.size / sizeof(t_meta))
	{
		if (priority(it[i - 1], it[i]) == TRUE)
		{
			swap_meta(&(it[i - 1]), &(it[i]));
			i = 1;
		}
		++i;
	}
}
