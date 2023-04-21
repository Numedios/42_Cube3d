/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:18:48 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 16:22:57 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	final_size;

	pointer = NULL;
	if (size && size * nmemb / size != nmemb)
		return (NULL);
	final_size = nmemb * size;
	if (final_size == 0)
	{
		pointer = malloc(sizeof(char));
		if (pointer == NULL)
			return (NULL);
		return (pointer);
	}
	pointer = malloc (final_size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, final_size);
	return (pointer);
}
