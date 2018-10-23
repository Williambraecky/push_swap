/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:32:32 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/10/23 18:59:27 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_common.h"

void	ft_exit_error(char *str)
{
	if (str != NULL)
		ft_printf_fd(2, "An error occured: %s\n", str);
	else
		ft_putstr_fd("Error\n", 2);
	exit(1);
}
