/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:08:39 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 19:10:23 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

static void	ft_isa(t_ps *ps, int print)
{
	if (print)
		ft_putstr("sa\n");
	if (ps->size_a <= 1)
		return ;
	ft_swapint(ps->pile_a + ft_index(ps, 0, PILE_A),
				ps->pile_a + ft_index(ps, 1, PILE_A));
}

void		ft_sa(t_ps *ps)
{
	ft_isa(ps, ps->print);
}

static void	ft_isb(t_ps *ps, int print)
{
	if (print)
		ft_putstr("sb\n");
	if (ps->size_b <= 1)
		return ;
	ft_swapint(ps->pile_b + ft_index(ps, 0, PILE_B),
				ps->pile_b + ft_index(ps, 1, PILE_B));
}

void		ft_sb(t_ps *ps)
{
	ft_isb(ps, ps->print);
}

void	ft_ss(t_ps *ps)
{
	if (ps->print)
		ft_putstr("ss\n");
	ft_isa(ps, 0);
	ft_isb(ps, 0);
}
