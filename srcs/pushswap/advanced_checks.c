/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:19:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/09 16:31:46 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_find_biggest_b(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ps->size_b)
	{
		if (ps->pile_b[ft_index(ps, i, PILE_B)] >
				ps->pile_b[ft_index(ps, j, PILE_B)])
			j = i;
		i++;
	}
	return (j);
}

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

	movs[0] = from;
	movs[1] = ps->size_a - from;
	movs[2] = position;
	movs[3] = ps->size_b - position;
	movs[4] = LIB_INT_MAX;
	if ((movs[0] >= movs[2] || movs[2] - movs[0] <= movs[3])
			&& movs[0] < movs[4] && (strat = TOP))
		movs[4] = movs[0] + ft_max(0, movs[2] - movs[0]);
	if ((movs[1] >= movs[3] || movs[3] - movs[1] <= movs[2])
			&& movs[1] < movs[4] && (strat = BOTTOM))
		movs[4] = movs[1] + ft_max(0, movs[3] - movs[1]);
	if ((movs[2] >= movs[0] || movs[0] - movs[2] <= movs[1])
			&& movs[2] < movs[4] && (strat = TOP))
		movs[4] = movs[2] + ft_max(0, movs[0] - movs[2]);
	if ((movs[3] >= movs[1] || movs[1] - movs[3] <= movs[0])
			&& movs[3] < movs[4] && (strat = BOTTOM))
		movs[4] = movs[3] + ft_max(0, movs[1] - movs[3]);
	if (movs[4] > ft_min(movs[0], movs[1]) + ft_min(movs[2], movs[3])
			&& (strat = BOTH))
		movs[4] = ft_min(movs[0], movs[1]) + ft_min(movs[2], movs[3]);
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

int		ft_find_smartest_move(t_ps *ps, int movs[2])
{
	int	i;
	int	current_pos;
	int	current_mov;
	int	j;

	movs[0] = LIB_INT_MAX;
	movs[1] = LIB_INT_MAX;
	i = 0;
	j = 0;
	while (i < ps->size_a && movs[1] >= 3)
	{
		current_pos = ft_calc_position(ps, ps->pile_a[ft_index(ps, i, PILE_A)]);
		current_mov = ft_calc_movements(ps, i, current_pos);
		if (current_mov < movs[1])
		{
			j = i;
			movs[0] = current_pos;
			movs[1] = current_mov;
		}
		i++;
	}
	return (j);
}

void	ft_advanced_checks(t_ps *ps)
{
	int	movs[2];
	int	j;
	int mvmnts;

	while (ps->size_a && !ft_is_ordered(ps))
	{
		j = ft_find_smartest_move(ps, movs);
		ft_push_position(ps, j, movs[0]);
		ft_check_rotation_only(ps);
	}
	mvmnts = ft_find_biggest_b(ps);
	if (mvmnts <= ps->size_b / 2)
		while (mvmnts--)
			ft_rb(ps);
	else
		while (mvmnts++ < ps->size_b)
			ft_rrb(ps);
	while (ps->size_b)
	{
		if (ps->pile_a[ps->maxsize - 1] >
				ps->pile_b[ft_index(ps, 0, PILE_B)] &&
			ps->pile_a[ps->maxsize - 1] <
				ps->pile_a[ft_index(ps, 0, PILE_A)])
			ft_rra(ps);
		ft_pa(ps);
	}
	while (ps->pile_a[ps->maxsize - 1] < ps->pile_a[0])
		ft_rra(ps);
}
