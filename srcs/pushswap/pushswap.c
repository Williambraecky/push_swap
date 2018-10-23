/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:18:20 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/23 17:59:19 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int argc, char *argv[])
{
	t_ps *ps;

	if (argc == 1)
		return (0);
	ps = ft_read_input(argc, argv);
	ps->print = 1;
	ft_check_basics(ps);
	if (!ft_is_ordered(ps))
		ft_advanced_checks(ps);
	ft_free_ps(ps);
	return (0);
}
