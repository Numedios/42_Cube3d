/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:52:32 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 12:49:48 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_copy;
	unsigned char	*src_copy;
	size_t			i;

	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			dest_copy[i] = src_copy[i];
			i++;
		}
	}
	else if (dest > src)
	{
		i = n;
		while (n-- > 0)
			dest_copy[n] = src_copy[n];
	}
	return (dest_copy);
}
