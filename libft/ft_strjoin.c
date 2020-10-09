/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:06:25 by suhong            #+#    #+#             */
/*   Updated: 2020/10/06 11:59:26 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		size_1;
	int		size_2;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	i = 0;
	if ((tmp = (char *)malloc((size_1 + size_2 + 1) * sizeof(char))) == 0)
		return (0);
	while (i < size_1 + size_2)
	{
		if (i < size_1)
			tmp[i] = s1[i];
		else
			tmp[i] = s2[i - size_1];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
