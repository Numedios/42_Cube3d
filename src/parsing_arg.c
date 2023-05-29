/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelabba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:46:20 by sbelabba          #+#    #+#             */
/*   Updated: 2023/05/24 18:46:21 by sbelabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 
	cherche si search est les dernier caractere de str
	utile pour.cub
*/

void	ft_strstrend(char *str, char *search)
{
	int	i;

	i = 0;
	if (!str && !search)
		exit (1);
	while (ft_strlen(str) != ft_strlen(search))
		str++;
	while (search[i])
	{
		if (search[i] != str[i])
		{
			printf("ERROR :\nfichier ne fini pas par %s\n", search);
			exit (1);
		}
		i++;
	}
}

/*
	voit si le fichier file s'ouvre avec l'option de lecture
*/
void	ft_try_open(char *file)
{
	int	fd;

	fd = open(file, 00400);
	if (fd == -1)
	{
		printf("ERROR :\nfichier %s invalide \n", file);
		exit (1);
	}
	close(fd);
}

/*
	verifie que l'argument du main existe et est valide
*/
void	parsing_arg(int argc, char **argv)
{
	if (argc != 1)
	{
		printf("ERROR :\nargc = %d\n", argc);
		exit (0);
	}
	ft_strstrend(argv[0], ".cub");
	ft_try_open(argv[0]);
}
