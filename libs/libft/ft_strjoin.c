/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:06:20 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 16:28:44 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen ((char *)s1);
	s2_len = ft_strlen ((char *)s2);
	s = malloc ((s1_len + s2_len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	s1_len = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[s1_len])
	{
		s[i] = s2[s1_len];
		i++;
		s1_len++;
	}
	s[i] = '\0';
	return (s);
}
/*
int main()
{
    printf ("%s", ft_strjoin("hello","toi"));
    return(0);
}*/
