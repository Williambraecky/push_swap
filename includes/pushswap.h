/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:26:29 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/09/27 14:36:11 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ps_common.h"

# define TOP 0
# define BOTTOM 1

/*
** Checks
*/

void	ft_check_basics(t_ps *ps);
void	ft_advanced_checks(t_ps *ps);

/*
** Utils
*/

int		ft_calc_position(t_ps *ps, int data);
int		ft_calc_movements(t_ps *ps, int from, int position);
int		ft_pivot_cmp(int *a, int *b);
void	ft_pivot_list_del(void *content, size_t len);

#endif
