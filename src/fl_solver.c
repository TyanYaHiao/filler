/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:30:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_filler.h"

int			check_solve(t_filler *filler)
{
	int		x;
	int		y;
	int		ab[2];

	x = 0;
	y = 0;
	ab[0] = 0;
	ab[1] = 0;
	while (x < filler->map_s_x)
	{
		y = 0;
		while (y < filler->map_s_y)
		{
			if (filler->map[x][y] == 'A')
				ab[0]++;
			if (filler->map[x][y] == 'B')
				ab[1]++;
			y++;
		}
		x++;
	}
	if (ab[0] == 1 && ab[1] == 0)
		return (1);
	else
		return (0);
}

void		place_piece(t_filler *filler, int map_x, int map_y)
{
	int		x;
	int		y;

	x = 0;
	while (x < filler->trim_s_x)
	{
		y = 0;
		while (y < filler->trim_s_y)
		{
			if (filler->piece_trimmed[x][y] == '*' &&\
			filler->map[map_x + x][map_y + y] == '.')
				filler->map[map_x + x][map_y + y] = '*';
			else if (filler->piece_trimmed[x][y] == '*' &&\
			(filler->map[map_x + x][map_y + y] == filler->player ||\
			filler->map[map_x + x][map_y + y] == filler->player - 32))
				filler->map[map_x + x][map_y + y] = 'A';
			else if (filler->piece_trimmed[x][y] == '*' &&\
			(filler->map[map_x + x][map_y + y] == filler->enemy ||\
			filler->map[map_x + x][map_y + y] == filler->enemy - 32))
				filler->map[map_x + x][map_y + y] = 'B';
			y++;
		}
		x++;
	}
}

void		locate_enemy(t_filler *filler)
{
	int		x;
	int		y;

	x = 0;
	while (x < filler->map_s_x)
	{
		y = 0;
		while (y < filler->map_s_y)
		{
			if (filler->map[x][y] == filler->enemy ||\
				filler->map[x][y] == filler->enemy - 32)
			{
				filler->enemy_x = x;
				filler->enemy_y = y;
				is_best_distance(filler);
			}
			y++;
		}
		x++;
	}
}

void		solve_filler(t_filler *filler)
{
	int		x;
	int		y;

	x = 0;
	filler->best_x = 1;
	filler->best_y = 1;
	while (x < filler->map_s_x)
	{
		y = 0;
		while (y < filler->map_s_y)
		{
			if (x + filler->trim_s_x <= filler->map_s_x &&\
				y + filler->trim_s_y <= filler->map_s_y)
				place_piece(filler, x, y);
			if (check_solve(filler))
			{
				filler->solve_x = x;
				filler->solve_y = y;
				locate_enemy(filler);
			}
			clear_map(filler);
			y++;
		}
		x++;
	}
}