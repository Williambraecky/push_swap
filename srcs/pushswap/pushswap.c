/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:18:20 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/28 19:16:20 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int argc, char *argv[])
{
	t_ps *ps;

	if (argc == 1)
		ft_exit_error(NULL);
	ps = ft_read_input(argc, argv);
	ps->print = 1;
	ft_check_basics(ps);
	if (!ft_is_ordered(ps))
		ft_quicksortt(ps);
	//ft_print_piles(ps);
	ft_free_ps(ps);
	return (0);
}
