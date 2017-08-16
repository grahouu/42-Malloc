#include "ft_malloc.h"
#include "ft_malloc_private.h"
#include <unistd.h>
#include <string.h>

/*
* Fill large ranges
*/
int					main(void)
{
	char *s;

	for (int i = 0; i < 100; ++i)
	{
		s = ft_malloc(SMALL_SIZE + 10);
		if (!s)
		{
			printf("[\x1b[31m TERR \x1b[0m] %s\n", "Fill large ranges");
			return (1);
		}
        memset((void *)s, 'a', SMALL_SIZE + 10);
        for (size_t j = 0; j < SMALL_SIZE + 10; ++j)
        {
            if (s[j] != 'a')
            {
                printf("[\x1b[31m FAIL \x1b[0m] %s\n", "Fill large ranges");
                return (1);
            }
        }
	}
	printf("[\x1b[32m OK \x1b[0m]   %s\n", "Fill large ranges");
	return (0);
}