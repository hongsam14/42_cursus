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
char	*ft_strdup(const char *s1);

int		main(void)
{
	char	dst[12] = "helloworld\n";
	char	*or_src;
	char	*src;
	int	size;

	or_src = (char *)malloc(sizeof(char) * 30);
#if 0
	size = ft_read(0, or_src, 30);
	or_src[size] = '\0';
	src = ft_strdup(or_src);
	ft_write(1, dst, ft_strlen(dst));
	ft_write(1, src, ft_strlen(src));
	printf("result:%d\n", ft_strcmp(dst, src));
	ft_write(1, ft_strcpy(dst, src), ft_strlen(dst));
#else
	/*
	size = read(0, or_src, 30);
	or_src[size] = '\0';
	src = strdup(or_src);
	write(1, dst, strlen(dst));
	write(1, src, strlen(src));
	printf("result:%d\n", strcmp(dst, src));
	write(1, strcpy(dst, src), strlen(dst));
	*/
#endif
	printf("%zd\n", write(-1, "test", 5));
	free(or_src);
	//free(src);
	return (0);
}
