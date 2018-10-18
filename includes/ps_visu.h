/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:58:15 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/18 19:02:59 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_VISU_H
# define PS_VISU_H

# include "ps_common.h"
# include "libft.h"
# include "mlx.h"
# include "keycode.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_TITLE "Visualizer"
# define DEFAULT_SPEED 16

typedef struct s_visu	t_visu;
typedef struct s_ctrl	t_ctrl;

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
	size_t	nb_moves;
	t_ctrl	controls;
};

void		ft_destroy_visu(t_visu *visu);
int			ft_handle_keypress(int key, t_visu *visu);
int			ft_loop(t_visu *visu);
void		ft_render(t_visu *visu);

#endif
