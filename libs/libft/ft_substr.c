/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_substr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: zhamdouc <zhamdouc@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/16 16:02:15 by zhamdouc		  #+#	#+#			 */
/*   Updated: 2022/05/18 11:40:43 by zhamdouc		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static char	*sub(char *s_copy, char *s1, size_t len, int start);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	taille_s;
	char			*s1;
	char			*s_copy;

	s_copy = (char *) s;
	taille_s = ft_strlen(s);
	if ((start >= taille_s) || len == 0)
	{
		s1 = malloc (1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = 0;
		return (s1);
	}
	if ((len + 1) < ((taille_s + 1) - start))
		s1 = malloc ((len + 1) * sizeof(char));
	else
		s1 = malloc (((taille_s + 1) - start) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	return (sub(s_copy, s1, len, start));
}

static char	*sub(char *s_copy, char *s1, size_t len, int start)
{
	size_t	n;

	n = 0;
	while (s_copy[start] && (n < len))
	{
		s1[n] = s_copy[start];
		start++;
		n++;
	}
	s1[n] = '\0';
	return (s1);
}
/*
int main()
{
	char *s= "tripouille";
	
	printf("%s", ft_substr(s, 100, 1));
}*/
// mettre une secruite si len est 0
// une autre si start est plus grand que la len de s 
