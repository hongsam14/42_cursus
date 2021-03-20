/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:08:43 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 21:31:09 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			open_cubfile(const char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (0);
	return (1);
}

int			skip_empty_lines(int fd, char **line)
{
	int		result;

	result = get_next_line(fd, line);
	while (**line == '\0' && result > 0)
	{
		free(*line);
		result = get_next_line(fd, line);
	}
	printf("%s\n", *line);
	return (result);
}

int			get_word(char *line, char ***content, int c)
{
	int		i;

	*content = ft_split(line, c);
	if (!*content)
		return (0);
	i = 0;
	while ((*content)[i])
		i++;
	return (i);
}

int			check_str(char *str, char *base)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (!ft_strchr(base, *str))
			return (0);
		str++;
	}
	return (1);
}

int			get_rgb(char *str, int *color)
{
	int		index;
	int		tmp;
	char	**rgb;

	index = get_word(str, &rgb, ',');
	*color = 0;
	if (index != 3)
		return (0);
	while (index)
	{
		if (!check_str(rgb[--index], "0123456789"))
			return (0);
		tmp = ft_atoi(rgb[index]);
		if (tmp < 0 || tmp > 255)
			return (0);
		if (index == 2)
			*color |= tmp << 16;
		if (index == 1)
			*color |= tmp << 8;
		if (index == 0)
			*color |= tmp;
		free(rgb[index]);
	}
	free(rgb);
	return (1);
}
