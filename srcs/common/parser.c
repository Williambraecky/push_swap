/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:24:54 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/23 17:57:55 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

int		ft_check_arg_validity(int argc, char **argv)
{
	int i;

	i = 0;
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

	i = 0;
	while (i < argc)
	{
		ps->pile_a[i] = ft_atoi(argv[i]);
		j = i - 1;
		while (j-- > 0)
		{
			if (ps->pile_a[j] == ps->pile_a[i])
			{
				ft_free_ps(ps);
				return (ft_exit_error(NULL));
			}
		}
		ps->intlen_max = ft_max(ps->intlen_max,
				ft_intlen(ps->pile_a[i]) + (ps->pile_a[i] < 0));
		i++;
	}
}

t_ps	*ft_parse_one_arg(char *str)
{
	t_ps	*ps;
	char	**argv;
	int		argc;

	if (!(argv = ft_strsplit(str, ' ')))
		ft_exit_error("Out of memory");
	argc = ft_splitlen(argv);
	if (!ft_check_arg_validity(argc, argv))
		ft_exit_error("TEST");
	if (!(ps = ft_memalloc(sizeof(*ps))))
		ft_exit_error("Out of memory");
	if (!(ps->pile_a = ft_memalloc(sizeof(*(ps->pile_a)) * (argc))) ||
			!(ps->pile_b = ft_memalloc(sizeof(*(ps->pile_b)) * (argc))))
		ft_exit_error("Out of memory");
	ps->size_a = argc;
	ps->size_b = 0;
	ps->maxsize = argc;
	ft_parse_args(ps, argc, argv);
	while (argc--)
		free(argv[argc]);
	free(argv);
	return (ps);
}

t_ps	*ft_read_input(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
		return (ft_parse_one_arg(argv[1]));
	if (!ft_check_arg_validity(argc - 1, argv + 1))
		ft_exit_error(NULL);
	if (!(ps = ft_memalloc(sizeof(*ps))))
		ft_exit_error("Out of memory");
	if (!(ps->pile_a = ft_memalloc(sizeof(*(ps->pile_a)) * (argc - 1))) ||
			!(ps->pile_b = ft_memalloc(sizeof(*(ps->pile_b)) * (argc - 1))))
		ft_exit_error("Out of memory");
	ps->size_a = argc - 1;
	ps->size_b = 0;
	ps->maxsize = argc - 1;
	ft_parse_args(ps, argc - 1, argv + 1);
	return (ps);
}
