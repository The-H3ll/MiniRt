/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:24:26 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/23 02:22:22 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *str;

	str = NULL;
	if (!(str = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
