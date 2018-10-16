/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:33:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/16 14:54:04 by wbraeckm         ###   ########.fr       */
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

int		ft_fill_mov_map(t_ps *ps, int from, int position, int movs[5])
{
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
	return (strat);
}

/*
** Calculate movements to push data to given position
** 1 calc time to push data to top
** + 1 push to other pile
** 2 calc time to rotate data to given position
** TODO: check if b_mov - a_mov < b_mov for TOP strat etc
*/

int		ft_calc_movements(t_ps *ps, int from, int position)
{
	int	movs[5];

	ft_fill_mov_map(ps, from, position, movs);
	return (movs[4] + 1);
}
