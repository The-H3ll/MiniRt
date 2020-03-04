/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_coordinate_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:37:01 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/21 14:47:01 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane		*plane_coordinate(t_strct *strct, char *str, int i)
{
	strct->plane->pos = take_pos(strct->plane->pos, &i, str);
	while (!(ft_isdigit(str[i])))
		i++;
	strct->plane->dir = take_pos(strct->plane->dir, &i, str);
	while (!ft_isdigit(str[i]))
		i++;
	strct->plane->color = take_color(strct->plane->color, &i, str);
	return (strct->plane);
}

void		go_next_(t_strct *strct, t_strct *head)
{
	if (head->cylindre->next == NULL)
	{
		head->cylindre->next = strct->cylindre;
		head->cylindre->next->next = NULL;
	}
	else if (head->cylindre->next->next == NULL)
	{
		head->cylindre->next->next = strct->cylindre;
		head->cylindre->next->next->next = NULL;
	}
	else if (head->cylindre->next->next->next == NULL)
	{
		head->cylindre->next->next->next = strct->cylindre;
		head->cylindre->next->next->next->next = NULL;
	}
	else if (head->cylindre->next->next->next->next == NULL)
		head->cylindre->next->next->next->next = strct->cylindre;
}
