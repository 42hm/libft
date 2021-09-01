/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:14:58 by hmoon             #+#    #+#             */
/*   Updated: 2021/05/28 23:02:14 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len_s1;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	len_s1 = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + len_s1)) && len_s1 > 0)
		len_s1--;
	if (!(ret = ft_substr(s1, 0, len_s1 + 1)))
		return (NULL);
	return (ret);
}
