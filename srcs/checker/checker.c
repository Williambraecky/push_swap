/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:07:50 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/25 16:51:28 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void	ft_read_operations(t_ps *ps)
{
	char	*str;
	int		ret;

	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (!ft_is_valid_operation(str))
		{
			ft_free_ps(ps);
			ft_exit_error(NULL);
		}
		ft_get_operation(str)(ps);
		ft_print_piles(ps);
	}
	if (ret == -1)
	{
		ft_free_ps(ps);
		ft_exit_error(NULL);
	}
}

int		main(int argc, char *argv[])
{
	t_ps *ps;

	if (argc == 1)
		ft_exit_error(NULL);
	ps = ft_read_input(argc, argv);
	ft_print_piles(ps);
	ft_read_operations(ps);
	if (ft_is_ordered(ps))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_ps(ps);
	return (0);
}
