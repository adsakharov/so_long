/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:58:58 by arupert           #+#    #+#             */
/*   Updated: 2022/06/18 19:30:53 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	x;
	int			i;

	len = ft_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	*(str + len) = '\0';
	i = 0;
	x = n;
	if (n < 0)
	{
		*(str + i) = '-';
		x = -x;
		i++;
	}
	while (len - 1 >= i)
	{
		*(str + len - 1) = (x % 10) + '0';
		x = x / 10;
		len --;
	}
	return (str);
}
