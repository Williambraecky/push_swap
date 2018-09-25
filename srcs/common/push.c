/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:12:33 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 19:11:00 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

void	ft_pb(t_ps *ps)
{
	if (ps->print)
		ft_putstr("pb\n");
	if (ps->size_a == 0)
		return ;
	ps->pile_b[ft_index(ps, -1, PILE_B)] = ps->pile_a[ft_index(ps, 0, PILE_A)];
	ps->size_a--;
	ps->size_b++;
}

void	ft_pa(t_ps *ps)
{
	if (ps->print)
		ft_putstr("pa\n");
	if (ps->size_b == 0)
		return ;
	ps->pile_a[ft_index(ps, -1, PILE_A)] = ps->pile_b[ft_index(ps, 0, PILE_B)];
	ps->size_b--;
	ps->size_a++;
}
