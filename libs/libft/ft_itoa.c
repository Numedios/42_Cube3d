/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:05:19 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 16:23:42 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		taille_int(long n_copy);
static char		*recursive_plus( char *s, long n, long len);
static char		*recursive_moins( char *s, long n, long len);

char	*ft_itoa(int n)
{
	long	n_copy;
	long	len;
	char	*s;

	n_copy = n;
	len = taille_int (n_copy);
	if (n >= 0)
	{
		len = (len + 2);
		s = malloc (len * sizeof(char));
		if (s == NULL)
			return (NULL);
		recursive_plus(s, n_copy, (len - 2));
	}
	if (n < 0)
	{
		len = (len + 3);
		s = malloc (len * sizeof(char));
		if (s == NULL)
			return (NULL);
		recursive_moins(s, n_copy, (len - 2));
	}
	s[len - 1] = '\0';
	return (s);
}

static int	taille_int(long n_copy)
{
	long	len;

	len = 0;
	if (n_copy < 0)
		n_copy = n_copy * -1;
	while (n_copy > 9)
	{
		n_copy = n_copy / 10;
		len++;
	}
	return (len);
}

static char	*recursive_plus( char *s, long n, long len)
{
	long	a;

	a = 0;
	while (len >= 0)
	{
		if (n > 9)
		{
			a = n % 10;
			n = n / 10;
		}
		if (len > 0)
			s[len] = a + 48;
		if (len == 0)
			s[len] = n + 48;
		len--;
	}
	return (s);
}

static char	*recursive_moins(char *s, long n, long len)
{
	long	a;

	a = 0;
	if (n < 0)
	{
		n = -1 * n;
		s[0] = '-';
	}
	while (len >= 1)
	{
		if (n > 9)
		{
			a = n % 10;
			n = n / 10;
		}
		if (len > 1)
			s[len] = a + 48;
		if (len == 1)
			s[len] = n + 48;
		len--;
	}
	return (s);
}

/*
int  main()
{
    printf("%s", ft_itoa(1234));
    return (0);
}*/
// vifier si le le int i que jenvoie pour ecrire le nom
