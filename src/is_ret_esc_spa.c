/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ret_esc_spa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:30:18 by marene            #+#    #+#             */
/*   Updated: 2014/04/29 09:30:10 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdlib.h>
int		*is_space(t_list *list, int *index, int *coords)
{
	select_list(list, index[0]);
	if (index[0] == index[3])
	{
		index[0] = 1;
		index[1] = 1;
		index[2] = 1;
	}
	else
	{
		if (index[1] == coords[2] - 2)
		{
			index[2]++;
			index[1] = 1;
		}
		else
			index[1]++;
		index[0]++;
	}
	coords = print_list(list, index[0]);
	return (coords);
}

void	is_return(struct termios term, t_list *list)
{
	reinit_term(term);
	send_selected(list);
	exit(0);
}

void	is_escape(struct termios term)
{
	reinit_term(term);
	exit(0);
}
