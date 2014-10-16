/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:31:17 by marene            #+#    #+#             */
/*   Updated: 2014/04/29 10:04:37 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <termcap.h>

static void	sig_sigquit(struct termios term)
{
	reinit_term(term);
	signal(SIGQUIT, SIG_DFL);
	ft_putendl("^\\Quit: 3");
	exit(0);
}

static void	sig_sigint(struct termios term)
{
	reinit_term(term);
	signal(SIGINT, SIG_DFL);
	ft_putendl("^C");
	exit(0);
}

static void	sig_sigtstp(struct termios term, char *cp)
{
	reinit_term(term);
	signal(SIGCONT, sig_handler);
	cp[0] = term.c_cc[VSUSP];
	cp[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static void	sig_sigcont(struct termios term)
{
	signal(SIGTSTP, sig_handler);
	init_term(term);
	while (g_sig_list->index == -1)
		g_sig_list = g_sig_list->next;
	print_list(g_sig_list, g_sig_index);
}

void		sig_handler(int sig)
{
	struct termios	term;
	char			buffer[2048];
	char			cp[2];

	tgetent(buffer, getenv("TERM"));
	tcgetattr(0, &term);
	if (sig == SIGWINCH)
		print_list(g_sig_list, g_sig_index);
	else if (sig == SIGTSTP)
		sig_sigtstp(term, cp);
	else if (sig == SIGCONT)
		sig_sigcont(term);
	else if (sig == SIGINT)
		sig_sigint(term);
	else if (sig == SIGQUIT)
		sig_sigquit(term);
}
