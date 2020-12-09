#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("ft_size:%d\n", ft_printf("ft:%.10d\n", 42));
	printf("or_size:%d\n", printf("or:%.10d\n", 42));
	return (0);
}
