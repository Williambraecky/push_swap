/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:33:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/27 22:26:20 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_find_smallest_b(t_ps *ps)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < ps->size_b)
	{
		if (ps->pile_b[ft_index(ps, i, PILE_B)] <
				ps->pile_b[ft_index(ps, j, PILE_B)])
			j = i;
		i++;
	}
	return (j);
}

int		ft_calc_position(t_ps *ps, int data)
{
	int	i;
	int	j;

	if (ps->size_b == 0)
		return (0);
	i = ft_find_smallest_b(ps);
	j = ps->size_b;
	while (j--)
	{
		if (ps->pile_b[ft_index(ps, i, PILE_B)] > data)
			break ;
		i--;
		if (i < 0)
			i = ps->size_b - 1;
	}
	return ((i + 1) % ps->size_b);
}

/*
** Calculate movements to push data to given position
** 1 calc time to push data to top
** + 1 push to other pile
** 2 calc time to rotate data to given position
** TODO: better movements calculation using rr and rrr
*/

int		ft_calc_movements(t_ps *ps, int from, int position)
{
	int	mvmnts;
	int	a_mov;
	int	b_mov;
	int	a_strat;
	int	b_strat;

	if (from <= ps->size_a / 2 && (a_strat = TOP))
		a_mov = from;
	else if ((a_strat = BOTTOM))
		a_mov = ps->size_a - from;
	if (position <= ps->size_b / 2 && (b_strat = TOP))
		b_mov = position;
	else if ((b_strat = BOTTOM))
		b_mov = ps->size_b - position;
	mvmnts = 1;
	if (a_strat == b_strat)
		mvmnts += ft_min(a_mov, b_mov) + ft_abs(a_mov - b_mov);
	else
		mvmnts += a_mov + b_mov;
	return (mvmnts);
}
