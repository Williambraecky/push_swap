/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 19:00:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/23 17:24:33 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	ft_render_a(t_visu *visu)
{
	int		i;
	t_lin	line;

	line.x1 = 0;
	line.y2 = 0;
	i = 0;
	while (i < visu->ps->size_a)
	{
		line.y1 = line.y2;
		line.x2 = ft_lerp(1, WIN_WIDTH / 2 - 1,
			ft_ilerp((float)visu->min, (float)visu->max,
			(float)ft_int_at(visu->ps, i, PILE_A)));
		i++;
		line.y2 = (int)(i * ((float)WIN_HEIGHT /
			(float)visu->ps->maxsize));
		line.color =
			ft_monochrome_p(ft_color_lerp(ft_int_to_color(START_COLOR),
				ft_int_to_color(END_COLOR), ft_ilerp((float)visu->min,
				(float)visu->max, (float)ft_int_at(visu->ps, i - 1, PILE_A))));
		ft_drawrect(visu, line, ft_color_to_int(line.color.start));
	}
}

void	ft_render_b(t_visu *visu)
{
	int		i;
	t_lin	line;

	line.x1 = WIN_WIDTH / 2 + 1;
	line.y2 = 0;
	i = 0;
	while (i < visu->ps->size_b)
	{
		line.y1 = line.y2;
		line.x2 = (int)ft_lerp((float)line.x1, (float)WIN_WIDTH,
			ft_ilerp((float)visu->min, (float)visu->max,
			(float)ft_int_at(visu->ps, i, PILE_B)));
		i++;
		line.y2 = (int)(i * ((float)WIN_HEIGHT /
			(float)visu->ps->maxsize));
		line.color =
			ft_monochrome_p(ft_color_lerp(ft_int_to_color(START_COLOR),
				ft_int_to_color(END_COLOR), ft_ilerp((float)visu->min,
				(float)visu->max, (float)ft_int_at(visu->ps, i - 1, PILE_B))));
		ft_drawrect(visu, line, ft_color_to_int(line.color.start));
	}
}

void	ft_render(t_visu *visu)
{
	char	*str;
	t_lin	line;

	mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
	line.x1 = WIN_WIDTH / 2;
	line.y1 = 0;
	line.y2 = WIN_HEIGHT;
	line.color = ft_monochrome_p(ft_int_to_color(0xD3D3D3));
	ft_drawvert(visu, line);
	ft_render_a(visu);
	ft_render_b(visu);
	str = ft_strformat("Size A: %d", visu->ps->size_a);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr,
		WIN_WIDTH / 2 / 2, 50, 0xD3D3D3, str);
	free(str);
	str = ft_strformat("Size B: %d", visu->ps->size_b);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr,
		WIN_WIDTH / 2 + (WIN_WIDTH / 2 / 2), 50, 0xD3D3D3, str);
	free(str);
	str = ft_strformat("Moves: %d; Current move: %d", visu->nb_moves,
		visu->controls.current_move);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, 10, 5, 0xD3D3D3, str);
	free(str);
	if (visu->controls.pause == 1 && (str = "Paused"))
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, 10, 20, 0xD3D3D3, str);
}
