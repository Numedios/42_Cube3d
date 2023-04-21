/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:19:00 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/05/20 12:11:40 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*s;

	s = pointer;
	while (count > 0)
	{
		*(s + (count - 1)) = value;
		count--;
	}
	return (pointer);
}
/*
int	main()
{
	int array[4]= {10, 20, 30, 40};
	int	value = 1;
	size_t size = sizeof (int) * 4;
	int	i = 0;

	ft_memset(array, value, size);
	while (i < 4)
	{
		printf("%d", array[i]);
		i++;
	}
	return (0);
}
*/