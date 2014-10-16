/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_selected.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:31:09 by marene            #+#    #+#             */
/*   Updated: 2014/01/12 20:31:10 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <libft.h>

void	send_selected(t_list *list)
{
	int		i;

	i = 0;
	while (list->index < list->next->index)
	{
		if (list->select == 1)
		{
			ft_putstr(list->name);
			ft_putchar(' ');
			i++;
		}
		list = list->next;
	}
	if (list->select == 1)
		ft_putstr(list->name);
	if (i > 0)
		ft_putchar('\n');
}
