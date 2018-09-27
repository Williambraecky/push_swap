/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:19:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/27 22:29:02 by wbraeckm         ###   ########.fr       */
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

/*
** Move to top then move to calculated position
** TODO: better movements calculation based on rr or rrr
*/

void	ft_push_position(t_ps *ps, int position, int target)
{
	int	a_strat;
	int	b_strat;

	if (position <= ps->size_a / 2)
		a_strat = TOP;
	else if ((a_strat = BOTTOM))
		position = ps->size_a - position;
	if (target <= ps->size_b / 2)
		b_strat = TOP;
	else if ((b_strat = BOTTOM))
		target = ps->size_b - target;
	while (target > 0 || position > 0)
	{
		if (a_strat == b_strat && target > 0 && position > 0)
			a_strat == TOP ? ft_rr(ps) : ft_rrr(ps);
		if (position > 0 && (a_strat != b_strat || target <= 0))
			a_strat == TOP ? ft_ra(ps) : ft_rra(ps);
		if (target > 0 && (a_strat != b_strat || position <= 0))
			b_strat == TOP ? ft_rb(ps) : ft_rrb(ps);
		target--;
		position--;
	}
	ft_pb(ps);
}

void	ft_end(t_ps *ps, int mvmnts)
{
	mvmnts = ft_find_biggest_b(ps);
	if (mvmnts <= ps->size_b / 2)
		while (mvmnts--)
			ft_rb(ps);
	else
		while (mvmnts++ < ps->size_b)
			ft_rrb(ps);
	while (ps->size_b)
		ft_pa(ps);
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
	while (i < ps->size_a)
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

	while (ps->size_a)
	{
		j = ft_find_smartest_move(ps, movs);
		ft_push_position(ps, j, movs[0]);
	}
	ft_end(ps, ft_find_biggest_b(ps));
}
