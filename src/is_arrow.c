/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:29:48 by marene            #+#    #+#             */
/*   Updated: 2014/01/12 20:29:50 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	is_arrow_left(int *index, int *coords)
{
	if (index[2] > 1)
	{
		index[2]--;
		index[0] = index[0] - coords[2] + 1;
	}
}

static void	is_arrow_right(int *index, int *coords)
{
	if (index[2] < coords[3] - 1 || (index[2] == coords[3] - 1
				&& index[0] + coords[2] < index[3] + 2))
	{
		index[2]++;
		index[0] = index[0] + coords[2] - 1;
	}
}

static void	is_arrow_down(int *index, int *coords)
{
	if (index[0] <= index[2] * coords[2] - 2 && index[0] < index[3])
	{
		index[1]++;
		index[0]++;
	}
	else if (index[0] > index[2] * coords[2] - 2 && index[0] < index[3])
	{
		index[0]++;
		index[2]++;
		index[1] = 1;
	}
	else if (index[0] == index[3])
	{
		index[0] = 1;
		index[1] = 1;
		index[2] = 1;
	}
}

static void	is_arrow_up(int *index, int *coords)
{
	if (index[0] > (1 + coords[2] * (index[2] - 1)))
	{
		index[1]--;
		index[0]--;
	}
	else if (index[0] <= (1 + coords[2] * (index[2] - 1)) && index[0] != 1)
	{
		index[0]--;
		index[2]--;
		index[1] = coords[3];
	}
	else if (index[0] == 1)
	{
		index[0] = index[3];
		index[2] = coords[3];
		index[1] = index[3] % coords[2];
	}
}

int			*is_arrow(t_list *list, char *buf, int *index, int *coords)
{
	if (buf[2] == 65)
		is_arrow_up(index, coords);
	else if (buf[2] == 66)
		is_arrow_down(index, coords);
	else if (buf[2] == 67)
		is_arrow_right(index, coords);
	else if (buf[2] == 68)
		is_arrow_left(index, coords);
	coords = print_list(list, index[0]);
	return (coords);
}
