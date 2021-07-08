/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:00:50 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 09:32:29 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_list	*build_token(t_list *token, char **spot, int len, int id)
{
	t_list	*add;
	char	*str_id;

	if (!(**spot) || len == 0)
		return (token);
	str_id = 0;
	if (id)
	{
		if (!ft_malloc(&str_id, sizeof(char) * 2))
			ft_error("malloc error");
		str_id[0] = (char)id;
		str_id[1] = 0;
	}
	add = ft_listnew2(ft_substr(*spot, 0, len), str_id);
	ft_listadd_tail(&token, &add);
	return (token);
}

static int	ft_make_token(t_list **token, char **spot, char **str, int *q_tmp)
{
	int		i;

	i = 1;
	if ((**spot) && **str == ' ')
	{
		(*token) = build_token((*token), spot, (*str) - (*spot), *q_tmp);
		*q_tmp = 0;
		(*spot) = 0;
	}
	else if (ft_strchr("><;|", **str))
	{
		(*token) = build_token((*token), spot, (*str) - (*spot), *q_tmp);
		*q_tmp = 0;
		if (**str && ft_strchr("><", **str) && **str == *((*str) + 1))
			i++;
		(*token) = build_token((*token), str, i, **str);
		(*spot) = 0;
	}
	return (i);
}

static void	split_init(t_list **token, char **spot, int *q_tmp, int *q_flag)
{
	(*token) = 0;
	(*spot) = 0;
	(*q_tmp) = 0;
	(*q_flag) = 0;
}

t_list	*ft_token_split(char *str)
{
	t_list	*token;
	char	*spot;
	int		q_flag;
	int		q_tmp;
	int		i;

	split_init(&token, &spot, &q_tmp, &q_flag);
	while (*str != 0)
	{
		i = 1;
		if (!spot)
		{
			while (*str == ' ')
				str++;
			spot = str;
		}
		q_flag = ft_check_quotes(*str, &q_tmp);
		if (!q_flag)
			i = ft_make_token(&token, &spot, &str, &q_tmp);
		str = str + i;
	}
	if (spot)
		token = build_token(token, &spot, str - spot, q_tmp);
	ft_check_quotes(0, 0);
	return (token);
}
