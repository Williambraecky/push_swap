/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:16:35 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/24 11:25:35 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	ft_img_put_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	*(int *)(image->data + (y * image->width + x) * image->bpp) = color;
}

void	ft_drawvert(t_visu *visu, t_lin line)
{
	int	y;
	int	starty;
	int	endy;

	if (line.y1 < line.y2)
	{
		starty = line.y1;
		endy = line.y2;
	}
	else
	{
		starty = line.y2;
		endy = line.y1;
	}
	y = starty - 1;
	while (y++ < endy)
		mlx_pixel_put(visu->mlx_ptr, visu->win_ptr,
			line.x1, y,
			ft_color_to_int(
				ft_col_p_lerp(line.color,
					ft_ilerp((float)starty, (float)endy, (float)y))));
}

void	ft_drawrect(t_image *image, t_lin line, int color)
{
	int y;

	if (!image)
		return ;
	y = line.y1;
	while (line.x1 <= line.x2)
	{
		line.y1 = y;
		while (line.y1 <= line.y2)
			ft_img_put_pixel(image, line.x1, line.y1++, color);
		line.x1++;
	}
}
