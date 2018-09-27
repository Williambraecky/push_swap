/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:33:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/27 18:03:57 by wbraeckm         ###   ########.fr       */
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
*/

int		ft_calc_movements(t_ps *ps, int from, int position)
{
	int	mvmnts;

	mvmnts = 0;
	if (from <= ps->size_a / 2)
		while (from--)
			mvmnts++;
	else
		while (from++ < ps->size_a)
			mvmnts++;
	mvmnts++;
	if (position <= ps->size_b / 2)
		while (position--)
			mvmnts++;
	else
		while (position++ < ps->size_b)
			mvmnts++;
	return (mvmnts);
}
