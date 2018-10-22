/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:58:15 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/22 17:54:56 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_VISU_H
# define PS_VISU_H

# include "ps_common.h"
# include "libft.h"
# include "mlx.h"
# include "keycode.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "Visualizer"
# define DEFAULT_SPEED 16
# define START_COLOR 0x1E90FF
# define END_COLOR 0xDC143C

typedef struct s_visu	t_visu;
typedef struct s_ctrl	t_ctrl;
typedef struct s_lin	t_lin;
typedef struct s_color	t_color;
typedef struct s_col_p	t_col_p;

struct		s_color
{
	int		r;
	int		g;
	int		b;
};

struct		s_col_p
{
	t_color	start;
	t_color	end;
};

struct		s_lin
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	t_col_p	color;
};

struct		s_ctrl
{
	int		pause;
	int		speed;
	int		ticks;
	size_t	current_move;
	int		next_move;
};

struct		s_visu
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_ps	*ps;
	char	**moves;
	int		min;
	int		max;
	size_t	nb_moves;
	t_ctrl	controls;
};

void		ft_destroy_visu(t_visu *visu);
int			ft_handle_keypress(int key, t_visu *visu);
int			ft_loop(t_visu *visu);
void		ft_render(t_visu *visu);
void		ft_drawvert(t_visu *visu, t_lin line);
void		ft_drawrect(t_visu *visu, t_lin line);

/*
** Color
*/

int			ft_rgb_to_int(int r, int g, int b);
int			ft_color_to_int(t_color color);
t_color		ft_rgb_to_color(int r, int g, int b);
t_color		ft_int_to_color(int rgb);
t_color		ft_color_lerp(t_color start, t_color end, float percent);
t_col_p		ft_colors_to_p(t_color start, t_color end);
t_color		ft_col_p_lerp(t_col_p col_p, float percent);
t_col_p		ft_monochrome_p(t_color color);

#endif
