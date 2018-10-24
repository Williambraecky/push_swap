/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:00:56 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/24 17:20:38 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visu.h"

void	ft_del_list(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

int		ft_read_moves(t_visu *visu)
{
	t_list	*list;
	char	*s;
	int		ret;

	list = NULL;
	while ((ret = get_next_line(0, &s)) > 0)
	{
		if (!ft_is_valid_operation(s))
		{
			ft_lstdel(&list, ft_del_list);
			return (0);
		}
		ft_lstpushback(&list, s, (ft_strlen(s) + 1));
		free(s);
	}
	if (ret == -1)
	{
		ft_lstdel(&list, ft_del_list);
		return (0);
	}
	visu->moves = (char **)ft_lsttoarray(list);
	visu->nb_moves = ft_lstlen(list);
	ft_lstdel(&list, ft_del_list);
	return (1);
}

t_visu	*ft_init_visu(int argc, char **argv)
{
	t_visu	*visu;

	if (!(visu = ft_memalloc(sizeof(t_visu))))
		exit(0);
	if (!(visu->mlx_ptr = mlx_init()) ||
		!(visu->win_ptr =
			mlx_new_window(visu->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE)))
	{
		ft_printf_fd(2, "Error: Could not init mlx");
		free(visu);
		exit(0);
	}
	if (!(visu->ps = ft_read_input(argc, argv)))
	{
		ft_printf_fd(2, "Error\n");
		mlx_destroy_window(visu->mlx_ptr, visu->win_ptr);
		free(visu);
		exit(0);
	}
	return (visu);
}

void	ft_calcminmax(t_visu *visu)
{
	int	i;

	i = 0;
	visu->min = LIB_INT_MAX;
	visu->max = LIB_INT_MIN;
	while (i < visu->ps->size_a)
	{
		visu->min = ft_min(visu->min, visu->ps->pile_a[i]);
		visu->max = ft_max(visu->max, visu->ps->pile_a[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_visu	*visu;
	t_lin	line;

	visu = ft_init_visu(argc, argv);
	if (ft_read_moves(visu) == 0)
	{
		ft_printf_fd(2, "Error\n");
		ft_destroy_visu(visu);
		return (0);
	}
	visu->controls.speed = DEFAULT_SPEED;
	ft_calcminmax(visu);
	line.x1 = WIN_WIDTH / 2;
	line.y1 = 0;
	line.y2 = WIN_HEIGHT;
	line.color = ft_monochrome_p(ft_int_to_color(0xD3D3D3));
	ft_drawvert(visu, line);
	mlx_loop_hook(visu->mlx_ptr, ft_loop, visu);
	mlx_key_hook(visu->win_ptr, ft_handle_keypress, visu);
	ft_render(visu);
	mlx_loop(visu->mlx_ptr);
	return (0);
}
