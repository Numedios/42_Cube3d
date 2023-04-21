/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheylkoss <zheylkoss@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:25 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/05/27 21:40:21 by zheylkoss        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*comparaison(int a, size_t len, char *base, char *found);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*base;
	char	*found;
	size_t	i;
	int		a;

	base = (char *) big;
	found = (char *) little;
	i = 0;
	a = 0;
	if (big == NULL || little == NULL)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	return (comparaison(a, len, base, found));
}

static char	*comparaison(int a, size_t len, char *base, char *found)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < len && base[i])
	{
		while (base[i] == found[j] && base[i] && i < len)
		{
			if (j == 0)
				a = i;
			i++;
			j++;
			if (found[j] == '\0')
				return (&((char *)base)[a]);
		}
		if (j > 0)
		{
			j = 0;
			i = a;
		}
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char	*big = "aaabcabcd";
	char	*little = "cd" ;
	size_t	len = 8;
	
//	printf("%d", strnstr(big, little, len));
	printf("%s", ft_strnstr(big, little, len));
	return (0);
}*/
