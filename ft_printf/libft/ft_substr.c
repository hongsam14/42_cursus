/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:01:32 by suhong            #+#    #+#             */
/*   Updated: 2020/10/06 11:58:41 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	size;
	unsigned int	i;

	if (s == 0)
		return (0);
	size = (unsigned int)ft_strlen(s);
	i = 0;
	if (size < start)
		return (ft_strdup(""));
	if ((p = (char *)malloc((len + 1) * sizeof(char))) == 0)
		return (0);
	while (i < len && start + i < size)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
