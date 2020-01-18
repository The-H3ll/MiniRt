/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:45:02 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/21 15:50:25 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *delete;

	while ((*lst))
	{
		delete = *lst;
		*lst = (*lst)->next;
		del(delete->content);
		free(delete);
	}
	lst = NULL;
}
