/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:07:50 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/12/03 15:33:49 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void	(*ft_get_operation(char *str))()
{
	if (ft_strequ(str, "sa"))
		return (ft_sa);
	else if (ft_strequ(str, "sb"))
		return (ft_sb);
	else if (ft_strequ(str, "ss"))
		return (ft_ss);
	else if (ft_strequ(str, "pa"))
		return (ft_pa);
	else if (ft_strequ(str, "pb"))
		return (ft_pb);
	else if (ft_strequ(str, "ra"))
		return (ft_ra);
	else if (ft_strequ(str, "rb"))
		return (ft_rb);
	else if (ft_strequ(str, "rr"))
		return (ft_rr);
	else if (ft_strequ(str, "rra"))
		return (ft_rra);
	else if (ft_strequ(str, "rrb"))
		return (ft_rrb);
	else if (ft_strequ(str, "rrr"))
		return (ft_rrr);
	return (NULL);
}

void	ft_read_operations(t_ps *ps)
{
	char	*str;
	int		ret;

	while ((ret = get_next_line(ps->opt.fd, &str)) > 0)
	{
		if (!ft_is_valid_operation(str))
		{
			ft_close_files(ps->opt);
			ft_free_ps(ps);
			ft_strdel(&str);
			ft_exit_error(NULL);
		}
		ft_get_operation(str)(ps);
		if (ps->opt.print_piles)
			ft_print_piles(ps);
		free(str);
	}
	if (ret == -1)
	{
		ft_close_files(ps->opt);
		ft_free_ps(ps);
		ft_exit_error(NULL);
	}
}

int		main(int argc, char *argv[])
{
	t_ps	*ps;
	t_opt	opt;

	if (argc == 1)
		return (0);
	opt = ft_read_opts(&argc, &argv);
	if (argc == 1)
	{
		ft_close_files(opt);
		return (0);
	}
	ps = ft_read_input(argc, argv);
	ps->opt = opt;
	if (opt.print_piles)
		ft_print_piles(ps);
	ft_read_operations(ps);
	if (ft_is_ordered(ps) && ps->size_a == ps->maxsize)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_close_files(opt);
	ft_free_ps(ps);
	return (0);
}
