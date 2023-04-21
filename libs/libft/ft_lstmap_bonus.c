/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:31:38 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/05/22 15:43:43 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*save;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	save = ft_lstnew(f(lst->content));
	if (save == NULL)
		return (NULL);
	new = save;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (new->next == NULL)
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (save);
}
