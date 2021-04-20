#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

int		main(void)
{
	char	dst[12] = "helloworld\n";
	char	*src;
	int	fd;

	src = (char *)malloc(sizeof(char) * 7);
	fd = open("./test", O_RDONLY);
#if 1
	ft_read(fd, src, 6);
	src[6] = '\0';
	ft_write(1, dst, ft_strlen(dst));
	ft_write(1, src, ft_strlen(src));
	printf("result:%d\n", ft_strcmp(dst, src));
	ft_write(1, ft_strcpy(dst, src), ft_strlen(dst));
#else
	read(fd, src, 6);
	src[6] = '\0';
	write(1, dst, strlen(dst));
	write(1, src, strlen(src));
	printf("result:%d\n", strcmp(dst, src));
	write(1, strcpy(dst, src), strlen(dst));
#endif
	return (0);
}
