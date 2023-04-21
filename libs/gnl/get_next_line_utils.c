/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:42:32 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/02 12:51:18 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*sub(char *s2, char *s1, size_t len, int start);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	s2 = (char *) s;
	i = ft_strlen2((char *)s);
	if ((start >= i) || len == 0)
	{
		s1 = malloc (1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = 0;
		return (s1);
	}
	if ((len + 1) < ((i + 1) - start))
		s1 = malloc ((len + 1) * sizeof(char));
	else
		s1 = malloc (((i + 1) - start) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	return (sub(s2, s1, len, start));
}

static char	*sub(char *s2, char *s1, size_t len, int start)
{
	size_t	n;

	n = 0;
	while (s2[start] && (n < len))
	{
		s1[n] = s2[start];
		start++;
		n++;
	}
	s1[n] = '\0';
	return (s1);
}

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		a;
	int		y;

	i = ft_strlen2 ((char *)s1);
	a = ft_strlen2 ((char *)s2);
	s = malloc ((i + a + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	y = 0;
	i = 0;
	while (s1[y])
	{
		s[y] = s1[y];
		y++;
	}
	while (s2[i])
	{
		s[y] = s2[i];
		y++;
		i++;
	}
	s[y] = '\0';
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}
