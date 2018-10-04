/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:26:29 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/04 19:56:02 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ps_common.h"

# define TOP 1
# define BOTTOM 2
# define BOTH 3

/*
** Checks
*/

void	ft_check_basics(t_ps *ps);
void	ft_advanced_checks(t_ps *ps);
void	ft_check_rotation_only(t_ps *ps);

/*
** Utils
*/

int		ft_calc_position(t_ps *ps, int data);
int		ft_calc_movements(t_ps *ps, int from, int position);
int		ft_pivot_cmp(int *a, int *b);
void	ft_pivot_list_del(void *content, size_t len);
void	ft_quicksortt(t_ps *ps);

#endif
