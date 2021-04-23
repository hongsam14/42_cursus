/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:01:53 by suhong            #+#    #+#             */
/*   Updated: 2020/10/06 12:00:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*f;
	char	*b;
	char	*tmp;

	if (s1 == 0 | set == 0)
		return (0);
	f = (char *)s1;
	while (ft_strchr(set, *f) != '\0' && *f != '\0')
		f++;
	b = (char *)s1 + ft_strlen(s1);
	while (ft_strchr(set, *b) != '\0' && b > f)
		b--;
	tmp = ft_substr(f, 0, b - f + 1);
	return (tmp);
}
