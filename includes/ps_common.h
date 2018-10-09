/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_common.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:26:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/10 00:15:55 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_COMMON_H
# define PS_COMMON_H

# include "libft.h"
# include <stdlib.h>

# define PILE_A 0
# define PILE_B 1

typedef struct s_pushswap	t_ps;
struct		s_pushswap
{
	int		*pile_a;
	int		size_a;
	int		*pile_b;
	int		size_b;
	int		maxsize;
	int		intlen_max;
	int		print;
};

/*
** Parsing
*/

t_ps		*ft_read_input(int argc, char **argv);

/*
** Utilitaries
*/

void		ft_exit_error(char *str);
void		ft_free_ps(t_ps *ps);
int			ft_is_ordered(t_ps *ps);
int			ft_index(t_ps *ps, int index, int pile);
void		ft_print_piles(t_ps *ps);
int			ft_is_valid_operation(char *str);
int			ft_int_at(t_ps *ps, int index, int pile);

/*
** Operations
*/

void		ft_sa(t_ps *ps);
void		ft_sb(t_ps *ps);
void		ft_ss(t_ps *ps);
void		ft_pa(t_ps *ps);
void		ft_pb(t_ps *ps);
void		ft_ra(t_ps *ps);
void		ft_rb(t_ps *ps);
void		ft_rr(t_ps *ps);
void		ft_rra(t_ps *ps);
void		ft_rrb(t_ps *ps);
void		ft_rrr(t_ps *ps);

#endif
