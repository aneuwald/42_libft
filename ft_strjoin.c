/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:21:40 by acanterg          #+#    #+#             */
/*   Updated: 2022/02/07 22:25:23 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	ft_memcpy(str, (char *)s1, len_s1);
	ft_memcpy(str + len_s1, (char *)s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
}
