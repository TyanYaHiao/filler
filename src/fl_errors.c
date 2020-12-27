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

#include "fl_filler.h"

void	util_malloc_error(char *str)
{
	ft_putendl("Malloc error: ");
	ft_putstr(str);
	ft_putendl(" not allocated!");
	exit(MALLOC_ERROR);
}
