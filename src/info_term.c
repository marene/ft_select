/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:29:25 by marene            #+#    #+#             */
/*   Updated: 2014/04/29 09:27:24 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <sys/ioctl.h>
#include <term.h>
#include <fcntl.h>

int		get_term_size(int select)
{
	struct winsize		term_size;
	int					fd;

	fd = open("/dev/tty", O_NOCTTY | O_WRONLY);
	ioctl(fd, TIOCGWINSZ, &term_size);
	close(fd);
	if (select == 1)
		return (term_size.ws_col);
	else if (select == 0)
		return (term_size.ws_row);
	else
		return (-1);
}
