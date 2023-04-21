/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sissaad <sissaad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:10:06 by sissaad           #+#    #+#             */
/*   Updated: 2022/06/03 19:27:33 by sissaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	printf("%d\n", strncmp(av[1], av[2], atoi(av[3])));
	printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
}*/