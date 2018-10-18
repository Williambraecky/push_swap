/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:25:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/18 18:28:03 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	ft_destroy_visu(t_visu *visu)
{
	mlx_destroy_window(visu->mlx_ptr, visu->win_ptr);
	ft_free_ps(visu->ps);
	while (visu->nb_moves--)
		free(visu->moves[visu->nb_moves]);
	free(visu->moves);
	free(visu);
}
