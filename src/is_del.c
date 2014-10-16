/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:30:02 by marene            #+#    #+#             */
/*   Updated: 2014/01/12 20:30:03 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>
#include <termios.h>
#include <stdlib.h>

static int	*del_elem(t_list **list, int *index, int *coords)
{
	index[3] = del_link(*list, index[0], index[3]);
	if (index[0] == 1)
		*list = (*list)->next;
	coords = print_list(*list, index[0]);
	return (coords);
}

static int	*del_last_elem_no_first_col(t_list *list, int *index, int *coords)
{
	index[3] = del_link(list, index[0], index[3]);
	index[0]--;
	index[2]--;
	coords = print_list(list, index[0]);
	return (coords);
}

static int	*del_last_elem_first_col(t_list *list, int *index, int *coords)
{
	index[3] = del_link(list, index[0], index[3]);
	index[0]--;
	index[1]--;
	index[2] = coords[3];
	coords = print_list(list, index[0]);
	return (coords);
}

static void	del_single_elem(t_list *list, struct termios term)
{
	free(list);
	reinit_term(term);
	exit(0);
}

int			*is_del(t_list **list, struct termios term, int *index, int *coords)
{
	if (index[3] == 1)
		del_single_elem(*list, term);
	else if (index[0] == index[3] && index[2] == 1)
		coords = del_last_elem_first_col(*list, index, coords);
	else if (index[0] == index[3] && index[2] != 1)
		coords = del_last_elem_no_first_col(*list, index, coords);
	else
		coords = del_elem(list, index, coords);
	return (coords);
}
