/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:10:30 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/05/20 20:15:25 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}
/*
int	main()
{
	int	c = 100;
	printf("%c\n", toupper(c));
	printf("%c\n", ft_toupper(c));
	return (0);
}
*/
