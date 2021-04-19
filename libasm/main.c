#include <sys/types.h>
#include <stdio.h>

ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
size_t	ft_strlen(const char *s);

int		main(void)
{
	int	i;
	
	ft_write(1, "helloworld\n", 11);
	i = ft_strlen("helloworld");
	printf("%d\n", i);
	return (0);
}
