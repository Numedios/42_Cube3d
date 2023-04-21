/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:00:10 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 12:33:41 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_copy;
	size_t			i;

	i = 0;
	s_copy = (unsigned char *)s;
	while (i < n)
	{
		s_copy[i] = '\0';
		i++;
	}
}

/*
int	main()
{
	char *s = "hello";
	size_t	n = 3;

	
	//printf("%s", s);
	ft_bzero(s, n);
	//printf("%s", s);
	return (0);
}
*/