/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:46:54 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 12:48:58 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_copy;
	char	*src_copy;

	dest_copy = (char *)dest;
	src_copy = (char *)src;
	while (n-- > 0)
	{
		dest_copy[n] = src_copy[n];
	}
	return (dest);
}
