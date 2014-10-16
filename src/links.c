/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:30:29 by marene            #+#    #+#             */
/*   Updated: 2014/01/12 20:30:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>
#include <stdlib.h>

int		set_index(t_list *list, int max_elem)
{
	int		i;

	i = 1;
	while (i < max_elem + 1)
	{
		list->index = i;
		list = list->next;
		i++;
	}
	return (i - 1);
}

void	select_list(t_list *list, int index)
{
	while (list && list->next && list->index != index)
		list = list->next;
	if (list->select)
		list->select = 0;
	else
		list->select = 1;
}

t_list	*make_cycle_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list->next)
		list = list->next;
	list->next = tmp;
	return (tmp);
}

int		del_link(t_list *list, int index, int max_elem)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = list;
	while (index != list->next->index)
		list = list->next;
	tmp = list->next;
	tmp->index = -1;
	list->next = list->next->next;
	if (index == 1)
		tmp2 = list->next;
	max_elem = set_index(tmp2, max_elem - 1);
	return (max_elem);
}

t_list	*add_link(t_list *list, char *name)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->select = 0;
		tmp->name = ft_strdup(name);
		tmp->next = list;
	}
	return (tmp);
}
