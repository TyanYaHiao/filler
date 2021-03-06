/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:30:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_filler.h"

int		main(void)
{
	t_filler	*fl;
	char		*line;

	if ((fl = (t_filler *)ft_memalloc(sizeof(t_filler))) == NULL)
		util_malloc_error("main struct");
	init_player(fl);
	while (get_next_line(0, &line))
	{
		parse_map(fl, line);
		parce_token(fl);
		trim_token(fl);
		solve_filler(fl);
		free_maps(fl);
		make_move(fl);
	}
}
