/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:33:47 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 12:48:02 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			i;

	s1_copy = (unsigned char *) s1;
	s2_copy = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1_copy[i] == s2_copy[i])
			i++;
		else
			return (s1_copy[i] - s2_copy[i]);
	}
	return (0);
}
/*
int	main()
{
	char	*s1 = "hello";
	char	*s2 = "helloo";
	size_t	n = 6;

	printf("%d\n", memcmp(s1, s2, n));
	printf("%d\n", ft_memcmp(s1, s2, n));
	return (0);

}
*/
