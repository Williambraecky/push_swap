/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:19:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/23 17:04:59 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_both_rotation(t_ps *ps, int movs[5])
{
	int a_strat;
	int b_strat;

	if (movs[0] <= movs[1])
		a_strat = TOP;
	else if ((a_strat = BOTTOM))
		movs[0] = movs[1];
	if (movs[2] <= movs[3])
		b_strat = TOP;
	else if ((b_strat = BOTTOM))
		movs[2] = movs[3];
	while (movs[0] > 0 || movs[2] > 0)
	{
		if (movs[0] > 0)
			a_strat == TOP ? ft_ra(ps) : ft_rra(ps);
		if (movs[2] > 0)
			b_strat == TOP ? ft_rb(ps) : ft_rrb(ps);
		movs[0]--;
		movs[2]--;
	}
}

/*
** Move to top then move to calculated position
*/

void	ft_push_position(t_ps *ps, int from, int position)
{
	int	movs[5];
	int	strat;

	strat = ft_fill_mov_map(ps, from, position, movs);
	if (strat == BOTH)
		ft_both_rotation(ps, movs);
	else
	{
		if (strat == BOTTOM)
			movs[0] = movs[1];
		if (strat == BOTTOM)
			movs[2] = movs[3];
		while (movs[0] > 0 || movs[2] > 0)
		{
			if (movs[0] > 0 && movs[2] > 0)
				strat == TOP ? ft_rr(ps) : ft_rrr(ps);
			if (movs[0] > 0 && movs[2] <= 0)
				strat == TOP ? ft_ra(ps) : ft_rra(ps);
			if (movs[2] > 0 && movs[0] <= 0)
				strat == TOP ? ft_rb(ps) : ft_rrb(ps);
			movs[0]--;
			movs[2]--;
		}
	}
	ft_pb(ps);
}

void	ft_find_smartest_move(t_ps *ps, int movs[5])
{
	int	i;

	movs[0] = LIB_INT_MAX;
	movs[1] = LIB_INT_MAX;
	i = 0;
	while (i <= ps->size_a / 2)
	{
		movs[2] = ft_calc_position(ps, ft_int_at(ps, i, PILE_A));
		movs[3] = ft_calc_movements(ps, i, movs[2]);
		if (movs[3] < movs[1])
		{
			movs[4] = i;
			movs[0] = movs[2];
			movs[1] = movs[3];
		}
		i++;
		movs[2] = ft_calc_position(ps, ft_int_at(ps, ps->size_a - i, PILE_A));
		movs[3] = ft_calc_movements(ps, ps->size_a - i, movs[2]);
		if (movs[3] < movs[1])
		{
			movs[4] = ps->size_a - i;
			movs[0] = movs[2];
			movs[1] = movs[3];
		}
	}
}

void	ft_post_checks(t_ps *ps)
{
	if (ft_int_at(ps, 0, PILE_A) < ft_int_at(ps, 0, PILE_B))
		while (ft_int_at(ps, ps->size_a - 1, PILE_A) >
			ft_int_at(ps, 0, PILE_B))
			ft_rra(ps);
	while (ps->size_b)
	{
		while (ps->pile_a[ps->maxsize - 1] >
				ps->pile_b[ft_index(ps, 0, PILE_B)] &&
			ps->pile_a[ps->maxsize - 1] <
				ps->pile_a[ft_index(ps, 0, PILE_A)])
			ft_rra(ps);
		ft_pa(ps);
	}
	while (ps->pile_a[ps->maxsize - 1] < ps->pile_a[0])
		ft_rra(ps);
}

void	ft_advanced_checks(t_ps *ps)
{
	int	movs[5];
	int mvmnts;

	while (ps->size_a > 5 && !ft_is_ordered(ps))
	{
		ft_find_smartest_move(ps, movs);
		ft_push_position(ps, movs[4], movs[0]);
		ft_check_rotation_only(ps);
	}
	if (ps->size_a == 5 && !ft_is_ordered(ps))
		ft_sort_5(ps);
	mvmnts = ft_find_biggest_b(ps);
	if (mvmnts <= ps->size_b / 2)
		while (mvmnts--)
			ft_rb(ps);
	else
		while (mvmnts++ < ps->size_b)
			ft_rrb(ps);
	ft_post_checks(ps);
}
