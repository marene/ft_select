/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:31:33 by marene            #+#    #+#             */
/*   Updated: 2014/04/29 09:32:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <libft.h>

t_list	*g_sig_list;
int		g_sig_index;

int		set_index(t_list *list, int max_elem);
int		*print_list(t_list *list, int index);
int		count_len(t_list *list);
void	select_list(t_list *list, int index);
t_list	*make_cycle_list(t_list *list);
int		del_link(t_list *list, int index, int max_elem);
t_list	*add_link(t_list *list, char *name);
int		is_prog(t_list *list, int max_elem);
void	send_selected(t_list *list);
int		get_term_size(int select);
int		tputs_putchar(int c);
void	ft_putstrtty(char *s);
int		*is_space(t_list *list, int *index, int *coords);
void	is_return(struct termios term, t_list *list);
void	is_escape(struct termios term);
int		*is_arrow(t_list *list, char *buf, int *index, int *coords);
int		*is_del(t_list **list, struct termios term, int *index, int *coords);
void	sig_handler(int sig);
void	reinit_term(struct termios term);
void	init_term(struct termios term);
void	init_signal(void);
int		*init_index(int max_elem);
int		*init_coords(t_list *list);
char	*init_read(t_list *list, int *index);

#endif
