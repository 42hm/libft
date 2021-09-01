/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:59:16 by hmoon             #+#    #+#             */
/*   Updated: 2021/06/03 02:33:51 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_num(int n)
{
	int cnt;

	cnt = (n <= 0 ? 1 : 0);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char			*ft_itoa(int n)
{
	unsigned int	num;
	int				count;
	char			*ret;

	num = (n > 0 ? n : -n);
	count = count_num(n);
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count > 0)
	{
		ret[count - 1] = (num % 10) + '0';
		num /= 10;
		count--;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
