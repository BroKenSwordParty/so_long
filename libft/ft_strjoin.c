/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:34:46 by jchamorr          #+#    #+#             */
/*   Updated: 2022/05/27 11:41:56 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	if (!s1)
		s1 = ft_strdup("");
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(l1 + l2 + 1);
	if (!s1 || !s2 || !str)
		return (NULL);
	l1 = 0;
	while (s1[l1])
	{
		str[l1] = s1[l1];
		l1++;
	}
	l2 = 0;
	while (s2[l2])
		str[l1++] = s2[l2++];
	str[l1] = '\0';
	free(s1);
	return (str);
}
