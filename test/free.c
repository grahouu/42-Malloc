#include "ft_malloc.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_d_size(int n)
{
	int			d_size;

	d_size = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		d_size = d_size * 10;
	}
	return (d_size);
}

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i += 1;
	}
}

char			*ft_itoa(size_t n)
{
	char		str[20];
	int			d_size;
    size_t      i;
	char		*save_ptr;

	save_ptr = str;
    i = 0;
	d_size = ft_d_size(n);
	while (d_size > 0)
	{
		str[i] = (n / d_size) + '0';
		n = n % d_size;
		d_size = d_size / 10;
        i++;
	}
	str[i] = '\0';
	return (save_ptr);
}

int					main(void)
{
	void	*m1 = ft_malloc(3096);
    void	*m2 = ft_malloc(1000);
    const int MAX = 50, MIN = 1;
    int     random;
    size_t  i = 0;
    int     count = 0;
    ft_malloc(1000);
    char    *m3 = (char*)ft_malloc(sizeof(char) * 20);

    while (count < 20)
    {
        random = (rand() % (MAX - MIN + 1)) + MIN;
        m3 = (char*)ft_malloc(sizeof(char) * random);
        i = 0;
        while (i <= (size_t)random)
        {
            m3[i] = 'r';
            i++;
        }
        count++;
    }

    print_mem_meta_data(10);
    ft_free(m1);

    print_mem_meta_data(10);
    ft_free(m2);
	
	print_mem_meta_data(10);
	write(1, "1.0\n", 4);
	return (0);
}