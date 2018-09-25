/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:16:44 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 19:09:54 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

static void	ft_ira(t_ps *ps, int print)
{
	int tmp;

	if (print)
		ft_putstr("ra\n");
	if (ps->size_a == 0)
		return ;
	tmp = ps->pile_a[ft_index(ps, 0, PILE_A)];
	ft_memmove(ps->pile_a + ft_index(ps, 0, PILE_A),
			ps->pile_a + ft_index(ps, 1, PILE_A),
			(ps->size_a * sizeof(*(ps->pile_a))));
	ps->pile_a[ft_index(ps, ps->size_a - 1, PILE_A)] = tmp;
}

void		ft_ra(t_ps *ps)
{
	ft_ira(ps, ps->print);
}

static void	ft_irb(t_ps *ps, int print)
{
	int tmp;

	if (print)
		ft_putstr("rb\n");
	if (ps->size_b == 0)
		return ;
	tmp = ps->pile_b[ft_index(ps, 0, PILE_B)];
	ft_memmove(ps->pile_b + ft_index(ps, 0, PILE_B),
			ps->pile_b + ft_index(ps, 1, PILE_B),
			(ps->size_b * sizeof(*(ps->pile_b))));
	ps->pile_b[ft_index(ps, ps->size_b - 1, PILE_B)] = tmp;

}

void		ft_rb(t_ps *ps)
{
	ft_irb(ps, ps->print);
}

void		ft_rr(t_ps *ps)
{
	if (ps->print)
		ft_putstr("rr\n");
	ft_ira(ps, 0);
	ft_irb(ps, 0);
}
