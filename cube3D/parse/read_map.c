/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:02:35 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 22:55:29 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int		destroy_list(t_row **list)
{
	t_row		*tmp;

	if (*list == 0)
		return (1);
	while (*list)
	{
		tmp = *list;
		free((*list)->content);
		free(*list);
		*list = tmp->next;
	}
	return (1);
}

static t_row	*init_row_data(char *str)
{
	t_row		*add;

	add = (t_row *)malloc(sizeof(t_row));
	if (!add || !str)
		return (0);
	add->w_size = ft_strlen(str);
	add->content = ft_strdup(str);
	if (!add->content)
		return (0);
	free(str);
	add->next = 0;
	return (add);
}

static t_row	*read_map(int fd)
{
	char		*tmp;
	t_row		*add;
	t_row		*lst;
	t_row		*start;
	int			result;

	lst = 0;
	start = 0;
	result = skip_empty_lines(fd, &tmp);
	while (result > 0 && tmp && check_str(tmp, "012NSWE "))
	{
		add = init_row_data(tmp);
		if (!add)
			return (0);
		if (!lst)
		{
			lst = add;
			start = lst;
		}
		else
		{
			lst->next = add;
			lst = lst->next;
		}
		result = get_next_line(fd, &tmp);
	}
	return (start);
}

static int		get_size(t_row *lst, int *w, int *h)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		if (j < lst->w_size)
			j = lst->w_size;
		lst = lst->next;
		i++;
	}
	*w = j;
	*h = i;
	printf("w : %d, h : %d \n", j, i);
	return (1);
}

int				make_square_map(int fd, int *w, int *h, char ***map)
{
	t_row		*lst;
	t_row		*start;
	int			y;

	lst = read_map(fd);
	if (!get_size(lst, w, h))
			return (0);
	*map = (char **)malloc(sizeof(char *) * *h + 1);
	if (!*map)
		return (0);
	y = -1;
	start = lst;
	while (++y < *h)
	{
		(*map)[y] = ft_calloc(sizeof(char), *w + 1);
		if (!(*map)[y])
			return (0);
		(*map)[y] = ft_memset((*map)[y], ' ', *w);
		(*map)[y] = ft_memcpy((*map)[y], lst->content, lst->w_size);
		lst = lst->next;
		printf("%s\n", (*map)[y]);
	}
	(*map)[y] = 0;
	return (destroy_list(&start));
}
