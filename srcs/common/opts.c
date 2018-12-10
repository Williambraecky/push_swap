/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:29:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/12/10 14:55:02 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void	ft_define_input(t_opt *opt, int *argc, char ***argv)
{
	(*argv) += 1;
	(*argc) -= 1;
	opt->fd = open((*argv)[1], O_RDONLY);
	if (opt->fd == -1)
		ft_exit_error("Could not open file");
	(*argv) += 1;
	(*argc) -= 1;
}

void	ft_define_output(t_opt *opt, int *argc, char ***argv)
{
	(*argv) += 1;
	(*argc) -= 1;
	opt->o_fd = open((*argv)[1], O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (opt->o_fd == -1)
		ft_exit_error("Could not open file");
	(*argv) += 1;
	(*argc) -= 1;
}

void	ft_close_files(t_opt opt)
{
	char	*str;

	while (opt.fd != 0 && get_next_line(opt.fd, &str) == 1)
		free(str);
	if (opt.fd != 0)
		close(opt.fd);
	if (opt.o_fd != 1)
		close(opt.o_fd);
}

t_opt	ft_read_opts(int *argc, char ***argv)
{
	t_opt	opt;

	opt.fd = 0;
	opt.print_piles = 0;
	opt.o_fd = 1;
	while ((*argv)[1][0] == '-' && !ft_strisnumber((*argv)[1]))
	{
		if (ft_strequ((*argv)[1], "-v"))
		{
			opt.print_piles = 1;
			(*argv) += 1;
			(*argc) -= 1;
		}
		else if (ft_strequ((*argv)[1], "-i"))
			ft_define_input(&opt, argc, argv);
		else if (ft_strequ((*argv)[1], "-o"))
			ft_define_output(&opt, argc, argv);
		else
			ft_exit_error("Invalid option");
	}
	return (opt);
}
