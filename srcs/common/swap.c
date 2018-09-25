/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:08:39 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 16:43:40 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

void	ft_sa(t_ps *ps)
{
	if (ps->size_a <= 1)
		return ;
	ft_swapint(ps->pile_a + ft_index(ps, 0, PILE_A),
				ps->pile_a + ft_index(ps, 1, PILE_A));
}

void	ft_sb(t_ps *ps)
{
	if (ps->size_b <= 1)
		return ;
	ft_swapint(ps->pile_b + ft_index(ps, 0, PILE_B),
				ps->pile_b + ft_index(ps, 1, PILE_B));
}

void	ft_ss(t_ps *ps)
{
	ft_sa(ps);
	ft_sb(ps);
}
