/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:31 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/06/09 16:26:08 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_1(char const *s, char c);
static void		*count_2(char const *s, char c, char **tab, int nb_words);
static void		remplir(char **tab, char const *s, char c, int j);
static char		**c_vide(char const *s);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_words;

	if (s == NULL)
		return (NULL);
	if (s[0] == 0)
	{
		tab = malloc (sizeof(char *));
		if (tab == NULL)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	if (c == 0)
		return (tab = c_vide(s));
	nb_words = count_1(s, c);
	tab = malloc (nb_words * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	count_2(s, c, tab, nb_words);
	remplir(tab, s, c, nb_words);
	return (tab);
}

static int	count_1(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

static void	*count_2(char const *s, char c, char **tab, int nb_words)
{
	int	j;
	int	i;
	int	compteur;

	i = -1;
	j = 0;
	while (++i < (nb_words - 1))
	{
		compteur = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			j++;
			compteur++;
		}
		tab[i] = malloc ((compteur + 1) * sizeof(char));
		if (tab[i] == NULL)
		{
			while (--i >= 0)
				free(tab[i]);
			return (NULL);
		}
	}
	return (0);
}

static void	remplir(char **tab, char const *s, char c, int nb_words)
{
	int	j;
	int	a;
	int	i;

	j = 0;
	a = 0;
	i = 0;
	while (j < (nb_words - 1))
	{
		while (s[i] == c)
			i++;
		a = 0;
		while (s[i] != c && s[i])
		{
			tab[j][a] = s[i];
			i++;
			a++;
		}
		tab[j][a] = '\0';
		j++;
	}
	tab[nb_words - 1] = NULL;
}

static char	**c_vide(char const *s)
{
	size_t		taille ;
	int			i;
	char		**abc;

	i = 0;
	taille = ft_strlen(s);
	abc = malloc (2 * sizeof(char *));
	if (abc == NULL)
		return (NULL);
	abc[0] = malloc ((taille + 1) * sizeof(char));
	if (abc[0] == NULL)
		return (NULL);
	while (s[i])
	{
		abc[0][i] = s[i];
		i++;
	}
	abc[0][i] = '\0';
	abc[1] = NULL;
	return (abc);
}
/*
int	main()
{
	char **tab;
    int i;
    
    i = 0;
    tab = ft_split("--1-2--", '-');
    while (tab[i])
    {
		printf("%ld", ft_strlen(tab[i]));
        printf("%s\n", tab[i]);
        i++;
    }
	printf("%s", tab[i]);
    return(0);
}*/