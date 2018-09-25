/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:16:44 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 15:22:21 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

void	ft_ra(t_ps *ps)
{
	int tmp;

	if (ps->size_a == 0)
		return ;
	tmp = ps->pile_a[ft_index(ps, 0, PILE_A)];
	ft_memmove(ps->pile_a + ft_index(ps, 0, PILE_A),
			ps->pile_a + ft_index(ps, 1, PILE_A),
			(ps->size_a * sizeof(*(ps->pile_a))));
	ps->pile_a[ft_index(ps, ps->size_a - 1, PILE_A)] = tmp;
}

void	ft_rb(t_ps *ps)
{
	int tmp;

	if (ps->size_b == 0)
		return ;
	tmp = ps->pile_b[ft_index(ps, 0, PILE_B)];
	ft_memmove(ps->pile_b + ft_index(ps, 0, PILE_B),
			ps->pile_b + ft_index(ps, 1, PILE_B),
			(ps->size_b * sizeof(*(ps->pile_b))));
	ps->pile_b[ft_index(ps, ps->size_b - 1, PILE_B)] = tmp;
}

void	ft_rr(t_ps *ps)
{
	ft_ra(ps);
	ft_rb(ps);
}
