/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:29:16 by marene            #+#    #+#             */
/*   Updated: 2014/04/29 09:27:00 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>
#include <termcap.h>
#include <stdlib.h>

int				count_len(t_list *list)
{
	size_t	max_len;

	max_len = 0;
	while (list->index < list->next->index)
	{
		if (ft_strlen(list->name) > max_len)
			max_len = ft_strlen(list->name);
		list = list->next;
	}
	if (ft_strlen(list->name) > max_len)
		max_len = ft_strlen(list->name);
	return (max_len + 1);
}

static void		move_up(int *coords)
{
	int			j;

	j = 0;
	while (j < coords[2])
	{
		tputs(tgetstr("up", NULL), 1, tputs_putchar);
		j++;
	}
}

static int		*get_lines_n_col(int *coords, t_list *list, int w_l)
{
	int			j;

	ft_putstrtty(list->name);
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
	tputs(tgetstr("do", NULL), 1, tputs_putchar);
	if (coords[3] == 1)
		coords[2]++;
	if (coords[2] + 1 > coords[0])
	{
		if (w_l == 0)
		{
			move_up(coords);
			coords[3]++;
		}
		j = 0;
		while (j < coords[1] * (coords[3] - 1))
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			j++;
		}
	}
	return (coords);
}

static int		*print_element(int *coords, t_list *list, int *written_lines,
							int index)
{
	coords[4] = coords[1] - ft_strlen(list->name);
	if (list->index == index)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
	if (list->select == 1)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	coords = get_lines_n_col(coords, list, *written_lines);
	return (coords);
}

int				*print_list(t_list *list, int index)
{
	int		*coords;
	int		written_lines;

	written_lines = 1;
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	coords = init_coords(list);
	while (list->index < list->next->index)
	{
		coords = print_element(coords, list, &written_lines, index);
		written_lines++;
		if (written_lines + 1 >= coords[0])
			written_lines = 0;
		list = list->next;
	}
	coords = print_element(coords, list, &written_lines, index);
	ft_putstrtty("\n");
	return (coords);
}
