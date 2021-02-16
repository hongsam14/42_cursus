#include <stdio.h>
#include "./mandatory/ft_printf.h"

int	main(void)
{
	while(1)
	{
		printf("ft_size:%d\n", ft_printf("ft:%.10d\n", 42));
	}
	printf("or_size:%d\n", printf("or:%.10d\n", 42));
	return (0);
}
