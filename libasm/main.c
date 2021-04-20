#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

int		main(void)
{
	char	dst[12] = "helloworld\n";
	char	src[4] = "Hi\n";
	
#if 1
	ft_write(1, dst, ft_strlen(dst));
	ft_write(1, src, ft_strlen(src));
	ft_write(1, ft_strcpy(dst, src), ft_strlen(dst));
#else
	write(1, dst, strlen(dst));
	write(1, src, strlen(src));
	write(1, strcpy(dst, src), strlen(dst));
#endif
	return (0);
}
