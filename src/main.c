/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:30:37 by marene            #+#    #+#             */
/*   Updated: 2014/01/12 20:30:38 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_select.h>

int		main(int argc, char **argv)
{
	t_list	*list;
	int		max_elem;

	if (argc == 1)
		return (0);
	list = NULL;
	max_elem = argc - 1;
	while (argc > 1)
	{
		list = add_link(list, argv[argc - 1]);
		argc--;
	}
	set_index(list, max_elem);
	list = make_cycle_list(list);
	if (is_prog(list, max_elem) == -1)
		ft_putendl_fd("Error: can't find term name", 2);
	return (0);
}
