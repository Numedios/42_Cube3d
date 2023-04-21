/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:43:51 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 16:24:16 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*f_s;
	int		i;
	int		s_len;

	i = 0;
	s_len = ft_strlen((char *)s);
	s_len = s_len + 1;
	f_s = malloc (s_len * sizeof(char));
	if (f_s == NULL)
		return (NULL);
	while (s[i])
	{
		f_s[i] = f(i, s[i]);
		i++;
	}
	f_s[i] = '\0';
	return (f_s);
}
