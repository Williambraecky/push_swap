/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:51:30 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/10 00:01:59 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

static char	*g_strs[] =
{
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	NULL
};

int			ft_is_valid_operation(char *str)
{
	int i;

	i = 0;
	while (g_strs[i])
		if (ft_strequ(g_strs[i++], str))
			return (1);
	return (0);
}

void		ft_print_piles(t_ps *ps)
{
	int i;

	i = ft_max(ps->size_a, ps->size_b) + 1;
	while (i > 0)
	{
		if (i > ps->size_a + 1)
			ft_printf("%*c", ps->intlen_max + 2, ' ');
		else if (i == ps->size_a + 1)
			ft_printf("{cyan}/%*c\\{eoc}", ps->intlen_max, 'A');
		else
			ft_printf("{cyan}|%*d|{eoc}", ps->intlen_max,
					ps->pile_a[ft_index(ps, ps->size_a - i, PILE_A)]);
		ft_printf("\t");
		if (i > ps->size_b + 1)
			ft_printf("\n");
		else if (i == ps->size_b + 1)
			ft_printf("{light_green}/%*c\\{eoc}\n", ps->intlen_max, 'B');
		else
			ft_printf("{light_green}|%*d|{eoc}\n", ps->intlen_max,
					ps->pile_b[ft_index(ps, ps->size_b - i, PILE_B)]);
		i--;
	}
}

int			ft_index(t_ps *ps, int index, int pile)
{
	if (pile == PILE_A)
		return (ps->maxsize - ps->size_a + index);
	else if (pile == PILE_B)
		return (ps->maxsize - ps->size_b + index);
	return (-1);
}

int			ft_int_at(t_ps *ps, int index, int pile)
{
	if (pile == PILE_A)
		return (ps->pile_a[ft_index(ps, index, pile)]);
	return (ps->pile_b[ft_index(ps, index, pile)]);
}

int			ft_is_ordered(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->size_a - 1)
	{
		if (ft_intcmp(ps->pile_a[ft_index(ps, i, PILE_A)],
					ps->pile_a[ft_index(ps, i + 1, PILE_A)]) > 0)
			return (0);
		i++;
	}
	return (1);
}
