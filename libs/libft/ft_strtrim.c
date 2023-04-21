/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtrim.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: zhamdouc <zhamdouc@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/16 19:49:05 by zhamdouc		  #+#	#+#			 */
/*   Updated: 2022/05/16 23:24:03 by zhamdouc		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			maxlen;
	char			*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	maxlen = ft_strlen(s1);
	while (maxlen && ft_strchr(set, s1[maxlen]))
		maxlen--;
	new = ft_substr(s1, start, maxlen + 1);
	return (new);
}
/*
int main()
{
	printf("%s", ft_strtrim(0,"eh"));
	return(0);
}*/
