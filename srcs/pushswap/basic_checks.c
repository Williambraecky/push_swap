/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:44:15 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 19:11:41 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_find_smallest(t_ps *ps)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < ps->size_a)
	{
		if (ps->pile_a[i] < ps->pile_a[j])
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
	i = j + 1;
	while (i < ps->size_a - 1)
	{
		if (ft_intcmp(ps->pile_a[j], ps->pile_a[i]) > 0)
			return ;
		i++;
	}
	if (j < ps->size_a / 2)
		while (j--)
			ft_ra(ps);
	else
		while (j++ < ps->size_a)
			ft_rra(ps);
}

void	ft_check_basics(t_ps *ps)
{
	ft_check_rotation_only(ps);
	if (!ft_is_ordered(ps))
		return ;
}
