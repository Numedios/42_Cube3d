/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:30:25 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/05/20 20:16:13 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	const void	*buf;

	buf = &c;
	write(fd, buf, 1);
}
// habituellement on utilise write avec des quotes,
// alors qu'ici on doit utiliser l'adresse du char