#include <sys/types.h>
#include <stdio.h>

ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
size_t	ft_strlen(const char *s);

int		main(void)
{
	ft_write(1, "helloworld\n", 11);
	printf("%zu\n", ft_strlen("helloworld\n"));
	return (0);
}
