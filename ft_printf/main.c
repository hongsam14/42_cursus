#include <stdio.h>
#include "./include/ft_printf.h"

int	main(void)
{
	printf("ft_size:%d\n", ft_printf("ft:%d\n", -1 * 2147483647 - 1));
	printf("or_size:%d\n", printf("or:%d\n", -1 * 2147483647 - 1));
	return (0);
}
