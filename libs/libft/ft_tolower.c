/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:43:12 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/05/20 12:32:28 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}

/*
int main ()
{
    int c = 'C';
    printf("%c", ft_tolower(c));
    return(0);
}
*/
