/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 18:40:34 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/28 19:16:34 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_get_pivot(t_ps *ps, int pile, int start, int end)
{
	int	*new;
	int	len;

	len = end - start;
	if (!(new = ft_memalloc(sizeof(*new) * len)))
		return (-1);
	ft_memcpy(new, (pile == PILE_A ? ps->pile_a : ps->pile_b),
			len * sizeof(*new));
	ft_intsort(new, (size_t)len, ft_intcmp);
	len = new[len / 2];
	free(new);
	return (len);
}

void	ft_quicksortt(t_ps *ps)
{
	int	pivot;
	int	i;

	i = ps->size_a;
	pivot = ft_get_pivot(ps, PILE_A, 0, ps->size_a);
	while (i--)
	{
		if (ft_intcmp(pivot, ps->pile_a[ft_index(ps, 0, PILE_A)]) <= 0)
			ft_pb(ps);
		else
			ft_ra(ps);
	}
	ft_print_piles(ps);
}
