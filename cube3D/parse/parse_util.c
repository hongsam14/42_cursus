/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:08:43 by suhong            #+#    #+#             */
/*   Updated: 2021/03/17 21:24:13 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		open_cubfile(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int		skip_empty_lines(int fd, char **line)
{
	int	result;

	result = get_next_line(fd, line);
	while (**line == '\0' && result > 0)
	{
		free(*line);
		result = get_next_line(fd, line);
	}
	printf("%s\n", *line);
	return (result);
}

int		get_word(char *line, char ***content, int c)
{
	int	i;

	*content = ft_split(line, c);
	if (!*content)
		return (0);
	i = 0;
	while ((*content)[i])
		i++;
	return (i);
}
