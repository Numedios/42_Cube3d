/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:03:36 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/05/22 17:17:50 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + srclen);
	if (i < size && src[i])
	{
		while (i < (size - dstlen - 1) && src[i] && i < (srclen + 1))
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[i + dstlen] = '\0';
	}
	return (dstlen + srclen);
}

/*
int main()
{
    char *dst = "BBBB";
    char *src = "AAAAAAAAA";
    size_t size = 6;

    printf ("%s", dst);
    ft_strlcat(dst, src, size);
    printf ("%s", dst);

}*/
