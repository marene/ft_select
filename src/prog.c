/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:30:50 by marene            #+#    #+#             */
/*   Updated: 2014/01/12 20:30:52 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			tputs_putchar(int c)
{
	int		fd;

	fd = open("/dev/tty", O_NOCTTY | O_WRONLY);
	if (isatty(fd))
		write(fd, &c, 1);
	else
		ft_putstrtty("not a valid tty");
	close(fd);
	return (1);
}

void		ft_putstrtty(char *s)
{
	int		n;
	int		fd;

	fd = open("/dev/tty", O_NOCTTY | O_WRONLY);
	n = ft_strlen(s);
	if (isatty(fd))
		write(fd, s, n);
	else
		ft_putstrtty("not a valid tty");
	close(fd);
}

void		reinit_term(struct termios term)
{
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	term.c_lflag |= (ICANON | ECHO | ISIG);
	tcsetattr(0, 0, &term);
}

static int	*init_prog(struct termios *term, t_list *list, int max, int **coord)
{
	int		*index;

	tcgetattr(0, term);
	init_term(*term);
	index = init_index(max);
	*coord = print_list(list, index[0]);
	init_signal();
	return (index);
}

int			is_prog(t_list *list, int max_elem)
{
	int				*index;
	int				*coords;
	struct termios	term;
	char			*buf;
	char			buffer[2048];

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	index = init_prog(&term, list, max_elem, &coords);
	while (1)
	{
		buf = init_read(list, index);
		if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
			is_escape(term);
		else if (buf[0] == 27 && buf[1] == 91 && buf[2] != 51)
			coords = is_arrow(list, buf, index, coords);
		else if ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0)
				|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 51))
			coords = is_del(&list, term, index, coords);
		else if (buf[0] == 10 && buf[1] == 0 && buf[2] == 0)
			is_return(term, list);
		else if (buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
			coords = is_space(list, index, coords);
	}
	return (0);
}
