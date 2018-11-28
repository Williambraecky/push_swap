/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 19:00:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/11/28 13:11:39 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

t_image	*ft_new_image(t_visu *visu, int width, int height)
{
	t_image		*img;

	if (!(img = malloc(sizeof(t_image))))
		return (NULL);
	img->img_ptr = mlx_new_image(visu->mlx_ptr, width, height);
	if (img->img_ptr == NULL)
	{
		ft_destroy_visu(visu);
		ft_exit_error("Could not allocate enough memory");
	}
	img->data = mlx_get_data_addr(img->img_ptr,
			&(img->bpp), &(img->size_line), &(img->endian));
	img->bpp /= 8;
	img->width = width;
	img->height = height;
	return (img);
}

void	ft_destroy_image(t_visu *visu, t_image *image)
{
	image->width = 0;
	image->height = 0;
	mlx_destroy_image(visu->mlx_ptr, image->img_ptr);
	free(image);
}

void	ft_render_a(t_visu *visu)
{
	int		i;
	t_lin	line;
	t_image	*image;

	if (!(image = ft_new_image(visu, WIN_WIDTH / 2 - 1, WIN_HEIGHT)))
		return ;
	line.x1 = 0;
	line.y2 = 0;
	i = 0;
	while (i < visu->ps->size_a)
	{
		line.y1 = line.y2;
		line.x2 = ft_lerp((float)1, (float)WIN_WIDTH / 2,
			ft_ilerp((float)visu->min, (float)visu->max,
			(float)ft_int_at(visu->ps, i++, PILE_A)));
		line.y2 = (int)(i * ((float)WIN_HEIGHT / (float)visu->ps->maxsize));
		line.color =
			ft_monochrome_p(ft_color_lerp(ft_int_to_color(START_COLOR),
				ft_int_to_color(END_COLOR), ft_ilerp((float)visu->min,
				(float)visu->max, (float)ft_int_at(visu->ps, i - 1, PILE_A))));
		ft_drawrect(image, line, ft_color_to_int(line.color.start));
	}
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, image->img_ptr, 0, 0);
	ft_destroy_image(visu, image);
}

void	ft_render_b(t_visu *visu)
{
	int		i;
	t_lin	line;
	t_image	*image;

	if (!(image = ft_new_image(visu, WIN_WIDTH / 2 - 1, WIN_HEIGHT)))
		return ;
	line.x1 = 0;
	line.y2 = 0;
	i = 0;
	while (i < visu->ps->size_b)
	{
		line.y1 = line.y2;
		line.x2 = (int)ft_lerp((float)1, (float)WIN_WIDTH / 2,
			ft_ilerp((float)visu->min, (float)visu->max,
			(float)ft_int_at(visu->ps, i++, PILE_B)));
		line.y2 = (int)(i * ((float)WIN_HEIGHT / (float)visu->ps->maxsize));
		line.color =
			ft_monochrome_p(ft_color_lerp(ft_int_to_color(START_COLOR),
				ft_int_to_color(END_COLOR), ft_ilerp((float)visu->min,
				(float)visu->max, (float)ft_int_at(visu->ps, i - 1, PILE_B))));
		ft_drawrect(image, line, ft_color_to_int(line.color.start));
	}
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr,
		image->img_ptr, WIN_WIDTH / 2 + 1, 0);
	ft_destroy_image(visu, image);
}

void	ft_render(t_visu *visu)
{
	char	*str;

	ft_render_a(visu);
	ft_render_b(visu);
	str = ft_strformat("Size A: %d", visu->ps->size_a);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr,
		WIN_WIDTH / 2 / 2, 50, 0xD3D3D3, str == NULL ? "(NULL)" : str);
	ft_strdel(&str);
	str = ft_strformat("Size B: %d", visu->ps->size_b);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr,
		WIN_WIDTH / 2 + (WIN_WIDTH / 2 / 2), 50, 0xD3D3D3,
		str == NULL ? "(NULL)" : str);
	ft_strdel(&str);
	str = ft_strformat("Moves: %d; Current move: %d", visu->nb_moves,
		visu->controls.current_move);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, 10, 5, 0xD3D3D3,
		str == NULL ? "(NULL)" : str);
	ft_strdel(&str);
	if (visu->controls.pause == 1 && (str = "Paused"))
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, 10, 20, 0xD3D3D3, str);
	if (visu->controls.reverse == 1 && (str = "Reversed"))
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, 10, 35, 0xD3D3D3, str);
	if (ft_is_ordered(visu->ps) && visu->ps->size_a == visu->ps->maxsize)
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, 10, 50, 0xD3D3D3,
			"Ordered");
}
