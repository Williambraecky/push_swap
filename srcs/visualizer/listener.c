/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:40:12 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/22 18:08:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

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

void	(*ft_get_rev_operation(char *str))()
{
	if (ft_strequ(str, "sa"))
		return (ft_sa);
	else if (ft_strequ(str, "sb"))
		return (ft_sb);
	else if (ft_strequ(str, "ss"))
		return (ft_ss);
	else if (ft_strequ(str, "pa"))
		return (ft_pb);
	else if (ft_strequ(str, "pb"))
		return (ft_pa);
	else if (ft_strequ(str, "ra"))
		return (ft_rra);
	else if (ft_strequ(str, "rb"))
		return (ft_rrb);
	else if (ft_strequ(str, "rr"))
		return (ft_rrr);
	else if (ft_strequ(str, "rra"))
		return (ft_ra);
	else if (ft_strequ(str, "rrb"))
		return (ft_rb);
	else if (ft_strequ(str, "rrr"))
		return (ft_rr);
	return (NULL);
}

void	ft_apply_choice(t_visu *visu)
{
	int		change;

	change = 0;
	if (visu->controls.next_move == 1)
	{
		if (visu->controls.current_move < visu->nb_moves && (change = 1))
			ft_get_operation(visu->moves[visu->controls.current_move++])
				(visu->ps);
	}
	else if (visu->controls.next_move == -1)
		if (visu->controls.current_move > 0 && (change = 1))
			ft_get_rev_operation(visu->moves[--visu->controls.current_move])
				(visu->ps);
	if (change)
		ft_render(visu);
	visu->controls.next_move = 0;
}

int		ft_loop(t_visu *visu)
{
	if (visu->controls.next_move ||
		visu->controls.current_move == visu->nb_moves)
		visu->controls.pause = 1;
	if (visu->controls.pause)
	{
		if (visu->controls.next_move)
			ft_apply_choice(visu);
		ft_render(visu);
		return (0);
	}
	visu->controls.ticks += visu->controls.speed;
	if (visu->controls.ticks < 60)
		return (0);
	while (visu->controls.ticks >= 60
		&& visu->controls.current_move < visu->nb_moves)
	{
		ft_get_operation(visu->moves[visu->controls.current_move++])(visu->ps);
		visu->controls.ticks -= 60;
	}
	ft_render(visu);
	return (0);
}

int		ft_handle_keypress(int key, t_visu *visu)
{
	if (key == ESC_KEY)
	{
		ft_destroy_visu(visu);
		exit(0);
	}
	else if (key == SP_KEY)
		visu->controls.pause ^= 1;
	else if (key == LEFT_KEY)
		visu->controls.next_move = -1;
	else if (key == RIGHT_KEY)
		visu->controls.next_move = 1;
	else if (key == MN_KEY && visu->controls.speed > 2)
		visu->controls.speed /= 2;
	else if (key == PL_KEY)
		visu->controls.speed *= 2;
	return (0);
}
