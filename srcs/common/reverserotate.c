/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:22:38 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/24 19:37:00 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

static void	ft_irra(t_ps *ps, int print)
{
	int	tmp;
	int	i;

	if (print)
		ft_putstr("rra\n");
	if (ps->size_a == 0)
		return ;
	tmp = ps->pile_a[ft_index(ps, ps->size_a - 1, PILE_A)];
	i = ps->size_a - 1;
	while (i--)
		ps->pile_a[ft_index(ps, i + 1, PILE_A)]
			= ps->pile_a[ft_index(ps, i, PILE_A)];
	ps->pile_a[ft_index(ps, 0, PILE_A)] = tmp;
}

void		ft_rra(t_ps *ps)
{
	ft_irra(ps, ps->print);
}

static void	ft_irrb(t_ps *ps, int print)
{
	int	tmp;
	int	i;

	if (print)
		ft_putstr("rrb\n");
	if (ps->size_b == 0)
		return ;
	tmp = ps->pile_b[ft_index(ps, ps->size_b - 1, PILE_B)];
	i = ps->size_b - 1;
	while (i--)
		ps->pile_b[ft_index(ps, i + 1, PILE_B)]
			= ps->pile_b[ft_index(ps, i, PILE_B)];
	ps->pile_b[ft_index(ps, 0, PILE_B)] = tmp;
}

void		ft_rrb(t_ps *ps)
{
	ft_irrb(ps, ps->print);
}

void		ft_rrr(t_ps *ps)
{
	if (ps->print)
		ft_putstr("rrr\n");
	ft_irra(ps, 0);
	ft_irrb(ps, 0);
}
