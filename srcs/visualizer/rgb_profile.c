/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_profile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:34:58 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/22 12:28:58 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

t_col_p		ft_colors_to_p(t_color start, t_color end)
{
	t_col_p	col_p;

	col_p.start = start;
	col_p.end = end;
	return (col_p);
}

t_col_p		ft_monochrome_p(t_color color)
{
	return (ft_colors_to_p(color, color));
}

t_color		ft_col_p_lerp(t_col_p col_p, float percent)
{
	return (ft_color_lerp(col_p.start, col_p.end, percent));
}
