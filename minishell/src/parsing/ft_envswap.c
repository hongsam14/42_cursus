/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:32 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 06:14:35 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_envlen(char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit((int)str[i]) || str[i] == '?')
		return (-1);
	while (str[i])
	{
		if (ft_strchr("$ ><|;\'\"=?", str[i]) || ft_isenv(str[i]) == ERROR)
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strswap(t_list **list, char *old, char *new, int oldlen)
{
	char	*res;

	if (!ft_malloc(&res, sizeof(char) * (ft_strlen((*list)->str) \
									- oldlen + ft_strlen(new))))
		return (0);
	ft_memcpy(res, (*list)->str, old - (*list)->str);
	ft_memcpy(res + (old - (*list)->str), new, ft_strlen(new));
	ft_memcpy(res + (old - (*list)->str) + ft_strlen(new), old + oldlen + 1, \
												ft_strlen(old + oldlen + 1));
	res[ft_strlen((*list)->str) - oldlen + ft_strlen(new) - 1] = 0;
	ft_free((*list)->str);
	ft_free(new);
	(*list)->str = res;
	return (res);
}

static void	jump_s_quotes(char *str, int *i)
{
	if (str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
	}
}

static int	ft_envswap2(t_list *list, t_list *env_list, int *i)
{
	char	*old;
	char	oldlen;
	char	*new;

	jump_s_quotes(list->str, i);
	old = ft_strchr(&(list->str[(*i)]), '$');
	if (old)
	{
		oldlen = ft_envlen(old + 1);
		if (oldlen == 0)
			return (ERROR);
		if (oldlen == -1)
			oldlen = 1;
		new = ft_getenv(env_list, old + 1, oldlen);
		ft_strswap(&list, old, new, oldlen);
		return (SUCCESS);
	}
	else
		return (ERROR);
}

void	ft_envswap(t_list *list, t_list *env_list)
{
	int		i;

	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (ft_envswap2(list, env_list, &i) == ERROR)
				break ;
		}
		list = list->next;
	}
}
