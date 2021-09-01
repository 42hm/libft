/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:18:14 by hmoon             #+#    #+#             */
/*   Updated: 2021/06/05 03:56:31 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	cset(char const *s, char c, size_t *count)
{
	size_t cnt;

	*count = 0;
	cnt = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			*count += 1;
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

static	char	**ret_free(char **ret, size_t i)
{
	while (i >= 0)
	{
		free(ret[i]);
		ret[i] = NULL;
		if (i == 0)
			break ;
		i--;
	}
	free(ret);
	ret = NULL;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	size;
	size_t	index;
	size_t	count;

	if (!s || !(ret = (char**)malloc(sizeof(char*) * (cset(s, c, &count) + 1))))
		return (NULL);
	index = 0;
	while (index < count)
	{
		size = 0;
		while (*s == c && *s != '\0')
			s++;
		while (s[size] != c && s[size] != '\0')
			size++;
		if (!(ret[index++] = ft_substr(s, 0, size)))
			return (ret_free(ret, index - 1));
		s += size;
	}
	ret[index] = 0;
	return (ret);
}
