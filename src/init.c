/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:29:34 by marene            #+#    #+#             */
/*   Updated: 2014/04/29 10:01:42 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>
#include <termcap.h>
#include <stdlib.h>

void	init_term(struct termios term)
{
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_lflag |= ISIG;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
}

void	init_signal(void)
{
	signal(SIGWINCH, sig_handler);
	signal(SIGCONT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}

int		*init_index(int max_elem)
{
	int		*index;

	index = malloc(sizeof(int) * 4);
	index[0] = 1;
	index[1] = 1;
	index[2] = 1;
	index[3] = max_elem;
	return (index);
}

int		*init_coords(t_list *list)
{
	int		*coords;

	coords = malloc(sizeof(int) * 6);
	coords[1] = count_len(list);
	coords[0] = get_term_size(0);
	coords[2] = 1;
	coords[3] = 1;
	coords[4] = 0;
	return (coords);
}

char	*init_read(t_list *list, int *index)
{
	char	*buf;

	buf = malloc(sizeof(char) * 4);
	ft_bzero(buf, 4);
	g_sig_list = list;
	g_sig_index = index[0];
	ft_bzero(buf, 3);
	read(0, buf, 4);
	return (buf);
}
