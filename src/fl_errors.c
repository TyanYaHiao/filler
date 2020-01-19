/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:30:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"filler.h"

void 	fl_player_errors_handler(t_filler *filler)
{
	if (ft_strcmp(&filler->player, "1") && ft_strcmp(&filler->player, "2"))
	{
		ft_putendl_fd("Parser error: wrong player!", 2);
		exit(PLAYER_ERROR);
	}
}

void	fl_util_malloc_error(char *str)
{
	ft_putendl("Malloc error: ");
	ft_putstr(str);
	ft_putendl(" not allocated!");
	exit(MALLOC_ERROR);
}
