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

void	init_player(t_filler *filler, char **line)
{
	get_next_line(0, line);

	if (ft_strstr(*line, "p2"))
	{
		filler->player = 'x';
		filler->enemy = 'o';
	}
	else
	{
		filler->player = 'o';
		filler->enemy = 'x';
	}
	free(*line);
}

int		main(void)
{
	t_filler	*filler;
	char		*line;

	if ((filler = (t_filler *)ft_memalloc(sizeof(t_filler))) == NULL)
		util_malloc_error("main struct");
	init_player(filler, &line);
	while (get_next_line(0, &line))
	{
		free(line);
		make_map(filler, line);
		make_piece(filler);
		trim_piece(filler);
		filler->best_solve_distance = 0;
		solve_filler(filler);
		ft_delmap(filler->map);
		ft_delmap(filler->piece);
		ft_delmap(filler->piece_trimmed);
		ft_putnbr(filler->best_x - filler->start_x);
		ft_putchar(' ');
		ft_putnbr(filler->best_y - filler->start_y);
		ft_putchar('\n');
	}
}
