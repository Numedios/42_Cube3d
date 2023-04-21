/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:42:10 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 12:46:51 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_copy;
	unsigned char	c_copy;

	c_copy = (unsigned char) c;
	s_copy = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s_copy[i] == c_copy)
			return ((void *) &s_copy[i]);
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	
	char	s[5]= "hello";
	int	c = 'o';
	size_t	n=2;

	printf("%s\n", (char *)ft_memchr(s,c,n));
	printf("%s\n", (char *)memchr(s,c,n));
list->content = 
zak->content = 
}
*/