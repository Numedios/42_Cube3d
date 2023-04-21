/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: zhamdouc <zhamdouc@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/10 22:54:04 by zhamdouc		  #+#	#+#			 */
/*   Updated: 2022/05/18 16:47:48 by zhamdouc		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t			lensrc;
	size_t			i;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	if (dst == NULL || src == NULL)
		return (0);
	dst_cpy = (unsigned char *) dst;
	src_cpy = (unsigned char *) src;
	i = 0;
	lensrc = ft_strlen((char *)src);
	while (((i + 1) < n) && (i <= lensrc) && src[i])
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	if (n > 0)
		dst_cpy[i] = '\0';
	return (lensrc);
}

/*int main()
{
	//ft_strlcpy(NULL,NULL, 10);
	char *dst = "hello";
	char	*src = "salut";

	printf ("%ld\n", ft_strlcpy(dst,src, -1));
	printf("%s\n", dst);
   // printf ("%d", strlcpy("hello", "", 10));
	return (0);
}*/
/*if ((i = ft_strlen((char *)src)) == 0)
	{
		if(n > 0)
			dst[0] = '\0';
		return (0);
	}
	else 
	{*/
