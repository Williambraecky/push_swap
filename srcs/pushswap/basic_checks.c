/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:44:15 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/10 00:35:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** /!\ These functions should only be called at the start
*/

int		ft_find_smallest(t_ps *ps)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < ps->size_a)
	{
		if (ps->pile_a[ft_index(ps, i, PILE_A)] <
				ps->pile_a[ft_index(ps, j, PILE_A)])
			j = i;
		i++;
	}
	return (j);
}

void	ft_check_rotation_only(t_ps *ps)
{
	int	i;
	int	j;

	j = ft_find_smallest(ps);
	i = 0;
	while (i < ps->size_a - 1)
	{
		if (ft_int_at(ps, (j + i) % ps->size_a, PILE_A) >
					ft_int_at(ps, (j + i + 1) % ps->size_a, PILE_A))
			return ;
		i++;
	}
	if (j <= ps->size_a / 2)
		while (j--)
			ft_ra(ps);
	else
		while (j++ < ps->size_a)
			ft_rra(ps);
}

int		ft_count_anomalies(t_ps *ps, int *canbefixed)
{
	int	i;
	int	j;
	int	count;
	int	prev_anomaly;

	j = ft_find_smallest(ps);
	i = 0;
	count = 0;
	prev_anomaly = 0;
	*canbefixed = 1;
	while (i < ps->size_a - 1)
	{
		if (ps->pile_a[ft_index(ps, (j + i) % ps->size_a, PILE_A)] >
					ps->pile_a[ft_index(ps, (j + i + 1) % ps->size_a, PILE_A)])
		{
			if (prev_anomaly)
				*canbefixed = 0;
			prev_anomaly = 1;
			count++;
		}
		else
			prev_anomaly = 0;
		i++;
	}
	return (count);
}

void	ft_fix_anomalies(t_ps *ps, int anomalies)
{
	int	i;
	int	canbefixed;
	int	min;

	min = ps->pile_a[ft_find_smallest(ps)];
	i = ps->size_a;
	while (i-- && anomalies)
	{
		if (ps->pile_a[ft_index(ps, 1, PILE_A)] != min &&
				ps->pile_a[ft_index(ps, 0, PILE_A)] >
				ps->pile_a[ft_index(ps, 1, PILE_A)])
		{
			anomalies--;
			ft_sa(ps);
		}
		if (anomalies)
			ft_ra(ps);
	}
	if ((anomalies = ft_count_anomalies(ps, &canbefixed)) == 0)
		return (ft_check_rotation_only(ps));
	if (anomalies > 0 && canbefixed)
		ft_fix_anomalies(ps, anomalies);
}

/*
** Count anomalies and do stuff if not a lot
** TODO: Handle simples cases like 2 1 3
*/

void	ft_check_basics(t_ps *ps)
{
	int	canbefixed;
	int	anomalies;

	ft_check_rotation_only(ps);
	if (ft_is_ordered(ps))
		return ;
	if (ps->size_a == 3)
		ft_sort_3(ps);
	if (ft_is_ordered(ps))
		return ;
	anomalies = ft_count_anomalies(ps, &canbefixed);
	// if (canbefixed)
	// 	ft_fix_anomalies(ps, anomalies);
	if (ft_is_ordered(ps))
		return ;
	if (ps->size_a == 4)
		ft_sort_4(ps);
}
