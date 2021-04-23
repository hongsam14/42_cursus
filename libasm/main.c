#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/errno.h>

ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int	main(void)
{
	char	*str;
	char	*str2;
	char	*copy;
	
	while (1)
	{
		str = (char *)calloc(30, sizeof(char));
		str2 = (char *)calloc(30, sizeof(char));
		printf("/////\nft_read\n/////\n");
		ft_read(1, str, 30);
		printf("\ns1:%s\n", str);
		printf("/////\norigin\n/////\n");
		ft_read(1, str2, 30);
		printf("\ns2:%s\n", str2);
		printf("/////\nft_write\n/////\n");
		printf("base:%s\n", str2);
		write(1, "my:", 3);
		ft_write(1, str2, strlen(str2));
		write(1, "\n", 1);
		write(1, "origin:", 7);
		write(1, str2, strlen(str2));
		write(1, "\n", 1);
		printf("/////\nft_strlen\n/////\n");
		printf("base:%s\n", str);
		printf("my:%zu\n", ft_strlen(str));
		printf("origin:%zu\n", strlen(str));
		printf("/////\nft_strcmp(%s,%s)\n/////\n", str, str2);
		printf("my:%d origin:%d\n", ft_strcmp(str, str2), strcmp(str, str2));
		printf("/////\nft_strdup(%s)\n/////\n", str);
		copy = ft_strdup(str);
		printf("my:%s\n", copy);
		free(copy);
		copy = strdup(str);
		printf("origin:%s\n", copy);
		printf("/////\nft_strcpy(%s, %s)\n/////\n", str, str2);
		printf("my:%s\n", ft_strcpy(str, str2));
		printf("origin:%s\n", strcpy(copy, str2));
		printf("/////\nend\n/////\n");
		free(str);
		free(str2);
		free(copy);
	}
	return (0);
}
