/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:44:47 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 20:02:05 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(fd, &(*s), 1);
		s++;
	}
	return ;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (*str1 == '\0' || *str2 == '\0')
		return (*str1 - *str2);
	i = 0;
	while ((*(str1 + i) != '\0' && *(str2 + i) != '\0'))
	{
		if (*(str1 + i) == *(str2 + i))
			i++;
		else
			return (*(str1 + i) - *(str2 + i));
	}
	return (*(str1 + i) - *(str2 + i));
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*(s + l) != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	j;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(s + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(s + i + j) = *(s2 + j);
		j++;
	}
	*(s + i + j) = '\0';
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == (char)c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + i);
	return (NULL);
}
