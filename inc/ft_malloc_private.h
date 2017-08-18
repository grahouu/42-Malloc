/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:11:22 by mlegendr          #+#    #+#             */
/*   Updated: 2017/08/18 15:11:24 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_PRIVATE_H

# define FT_MALLOC_PRIVATE_H

# include <unistd.h>
# include <stddef.h>
# include <pthread.h>

# define TINY_NB_PAGES	10
# define SMALL_NB_PAGES	100
# define TINY_SIZE	(size_t)(TINY_NB_PAGES * getpagesize() / 100)
# define SMALL_SIZE	(size_t)(SMALL_NB_PAGES * getpagesize() / 100)

typedef enum	e_type
{
	NONE,
	SLICE,
	TRANGE,
	SRANGE,
	LRANGE,
	NEXT,
	FREE
}				t_type;

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef struct	s_meta
{
	t_type		type;
	void		*ptr;
	size_t		size;
}				t_meta;

extern t_meta	g_mem_meta_data;
extern pthread_mutex_t	g_mutex;

void			*ft_malloc(size_t size);
void			ft_free(void *ptr);
void			*ft_realloc(void *ptr, size_t size);
void			*ft_calloc(size_t nmemb, size_t size);

/*
** brief: this function allocate a memory range which is biger or equal
**	 than size
** param: <size> min size to be allocated
** return: the memory range
*/
t_meta			new_memory_range(size_t size);

/*
** brief: this function allocate a meta range
** return: the meta range
*/
t_meta			new_meta_range(void);

/*
** brief: this function allocate a memory slice which is equal
**	 than size and store the slice in meta datas
** param: <size> size to be allocated
** return: the pointer on memory slice
*/
t_meta			*new_slice(const size_t size);

/*
** brief: this function find the first t_meta with the type NONE in metadatas.
**	 If the meta_range is full, a new meta range is created
** return: the t_meta found
*/
t_meta			*find_first_none_meta_data(void);

/*
** brief: this function check if the memory targeted by slice is in the
**	 memory targeted by range
** param: <slice> the slice to check
** param: <range> the range which may contain the slice
** return: TRUE if the slice is in the range, FALSE otherwise
*/
t_bool			is_slice_in_range(const t_meta slice, const t_meta range);

/*
** brief: this function check if the range as enough space to store the slice
**	 and find the begining of this space
** param: <range> the range to check
** param: <size> size to be allocated
** return: the pointer on memory, or NULL if the range as not enough space
*/
void			*find_empty_mem_in_range(const t_meta range, size_t size);

/*
** brief: this function check if the t_meta type is SLICE or FREE
** param: <slice> the t_meta to check
** return: TRUE if slice.type == SLICE or slice.type == FREE, FALSE otherwise
*/
t_bool			is_slice_or_free(const t_meta slice);

/*
** brief: this function check if the t_meta type is RANGE
** param: <range> the t_meta to check
** return: TRUE if range.type == TRANGE or range.type == SRANGE or
**	 range.type == LRANGE, FALSE otherwise
*/
t_bool			is_range(const t_meta range);

/*
** brief: this function find the t_meta by ptr.
** param: <ptr> pointer on memory to find
** param: <meta_type> type of t_meta to find
** return: the t_meta if found, NULL otherwise
*/
t_meta			*find_meta_data_by_ptr(void *ptr, t_type meta_type);

/*
** brief: this function find the range by meta.
** param: <meta_type> type of t_meta
** return: the t_meta if found, NULL otherwise
*/
t_meta			*find_range_by_meta(t_meta meta);

/*
** brief: this function check if range is empty.
** param: <meta_type> type of t_meta RANGE
** return: TRUE if empty, FALSE otherwise
*/
t_bool			is_range_empty(t_meta range);

/*
** brief: this function truncate a freed memory.
** param: <freed> t_meta to truncate
** param: <size> size to truncate
** return: the memory truncated
*/
void			*truncate_freed_memory(t_meta *freed, const size_t size);

/*
** brief: this function munmap a memory range and set t_meta type to NONE
** param: <range> the range to munmap
*/
void			del_memory_range(t_meta *range);

/*
** brief: this function free slice
** param: <slice> slice for free
*/
void			free_slice(t_meta *slice);

/*
** brief: this function return a string
** which correspond to the type
** param: <t> type of t_meta
** return: string serialized type
*/
const char		*type_to_str(t_type t);

/*
** brief: this function return number
** which correspond to the type
** param: <t> type of t_meta
** return: size_t
*/
size_t			count_type(t_type t);

/*
** brief: this function find and merge all
** contiguous FREE mem
*/
void			merge_freed(void);

/*
** brief: this function print a t_meta
** param: <md> t_meta to print
*/
void			print_one_meta_data(t_meta md);

/*
** brief: this function sort meta_data
*/
void			sort_meta_data(void);

/*
** brief: this function print a number
** param: <n> number to print
** param: <padding> min lenght of string, space
**	will be added if number sze < min size
** param: <base> base 2 -> 16
*/
void			ft_putnbr_padded(unsigned long n,
					unsigned long padding, unsigned long base);

/*
** brief: this function print a string
** param: <str> string to print
** param: <padding> min lenght of string, space
**	will be added if number sze < min size
*/
void			ft_putstr_padded(char const *s, size_t padding);
#endif
