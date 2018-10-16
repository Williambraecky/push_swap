/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:55:07 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/10 00:58:42 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_2(t_ps *ps) {
	if (ps->pile_a[ft_index(ps, 0, PILE_A)]
		> ps->pile_a[ft_index(ps, 1, PILE_A)])
		ft_sa(ps);
}

//2 1 3 | 1 3 2 | 3 2 1
void	ft_sort_3(t_ps *ps) {
	ft_check_rotation_only(ps);
	if (ft_is_ordered(ps))
		return ;
	if (ft_int_at(ps, 0, PILE_A) > ft_int_at(ps, 1, PILE_A)
		&& ft_int_at(ps, 0, PILE_A) < ft_int_at(ps, 2, PILE_A))
		ft_sa(ps);
	else if (ft_int_at(ps, 0, PILE_A) < ft_int_at(ps, 1, PILE_A)
		&& ft_int_at(ps, 1, PILE_A) > ft_int_at(ps, 2, PILE_A))
	{
		ft_sa(ps);
		ft_ra(ps);
	}
	else if (ft_int_at(ps, 0, PILE_A) > ft_int_at(ps, 1, PILE_A)
		&& ft_int_at(ps, 1, PILE_A) > ft_int_at(ps, 2, PILE_A))
	{
		ft_sa(ps);
		ft_rra(ps);
	}
}

void	ft_sort_4(t_ps *ps) {
	int i;

	i = ft_find_smallest(ps);
	if (i <= ps->size_a / 2)
		while (i--)
			ft_ra(ps);
	else
		while (i++ < ps->size_a)
			ft_rra(ps);
	ft_pb(ps);
	ft_sort_3(ps);
	ft_pa(ps);
}
