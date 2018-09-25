/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:24:54 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 17:01:49 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

int		ft_check_arg_validity(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strisnumber(argv[i]) ||
				ft_strlen(argv[i]) > 11 ||
				ft_atol(argv[i]) > (long)LIB_INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

void	ft_parse_args(t_ps *ps, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		ps->pile_a[i - 1] = ft_atoi(argv[i]);
		j = i - 1;
		while (j--)
		{
			if (ps->pile_a[j] == ps->pile_a[i - 1])
			{
				ft_free_ps(ps);
				return (ft_exit_error(NULL));
			}
		}
		ps->intlen_max = ft_max(ps->intlen_max,
				ft_intlen(ps->pile_a[i - 1]) + (ps->pile_a[i - 1] < 0));
		i++;
	}
}

t_ps	*ft_read_input(int argc, char **argv)
{
	t_ps	*ps;

	if (!ft_check_arg_validity(argc, argv))
		ft_exit_error(NULL);
	if (!(ps = ft_memalloc(sizeof(*ps))))
		ft_exit_error("Out of memory");
	if (!(ps->pile_a = ft_memalloc(sizeof(*(ps->pile_a)) * (argc - 1))) ||
			!(ps->pile_b = ft_memalloc(sizeof(*(ps->pile_b)) * (argc - 1))))
		ft_exit_error("Out of memory");
	ps->size_a = argc - 1;
	ps->size_b = 0;
	ps->maxsize = argc - 1;
	ft_parse_args(ps, argc, argv);
	return (ps);
}
