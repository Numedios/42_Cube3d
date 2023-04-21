/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:43:04 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 13:49:30 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*adresse;
	int				i;
	unsigned char	c_copy;

	c_copy = (unsigned char) c;
	i = 0;
	adresse = NULL;
	if (c_copy == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] != c_copy)
			i++;
		else
		{
			adresse = (char *) &s[i];
			i++;
		}
	}
	return (adresse);
}

// que faire si le string est compose uniquement de "\0"
// que faire si pointeur recu est null
/*
int     main()
{
        char string[]= "salut bonjourj";
        int     ch = 'q';

        printf("%s \n", strrchr(string, ch));
        printf("%s \n", ft_strrchr(string, ch));
}
*/
