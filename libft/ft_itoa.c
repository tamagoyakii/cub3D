/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:38:12 by jihyukim          #+#    #+#             */
/*   Updated: 2022/11/21 18:03:27 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_n_len(int n)
{
	size_t	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	if (n < 0)
		cnt++;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		n_len;
	long long	num;

	n_len = ft_n_len(n);
	str = (char *)malloc(sizeof(char) * n_len + 1);
	num = (long long)n;
	if (!str)
		return (0);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[n_len] = '\0';
	while (num)
	{
		str[n_len - 1] = num % 10 + 48;
		num /= 10;
		n_len--;
	}
	return (str);
}
