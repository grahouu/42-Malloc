#include "ft_malloc_private.h"

static t_meta	*find_first_none_meta_data_in_meta_range(t_meta meta_range)
{
	size_t	i;
	t_meta	*it;

	it = (t_meta*)meta_range.ptr;
	i = 0;
	while (i < meta_range.size / sizeof(t_meta))
	{
		if (it[i].type == NONE)
			return (&(it[i]));
		++i;
	}
	return (NULL);
}

static t_meta	*copy_meta_data(t_meta src, t_meta dst)
{
	size_t i;
	t_meta *s_it;
	t_meta *d_it;

	i = 0;
	s_it = (t_meta*)src.ptr;
	d_it = (t_meta*)dst.ptr;
	while (i < src.size / sizeof(t_meta))
	{
		d_it[i] = s_it[i];
		++i;
	}
	return (&(d_it[i]));
}

t_meta			*find_first_none_meta_data(void)
{
	t_meta	*none_meta;
	t_meta	tmp;

	none_meta = find_first_none_meta_data_in_meta_range(g_mem_meta_data);
	if (none_meta)
		return (none_meta);
	tmp = new_meta_range();
	none_meta = copy_meta_data(g_mem_meta_data, tmp);
	del_memory_range(&g_mem_meta_data);
	g_mem_meta_data = tmp;
	return (none_meta);
}
