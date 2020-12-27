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

int			check_solve(t_filler *fl)
{
	int		x;
	int		y;
	int		player_counter;
	int		enemy_counter;

	player_counter = 0;
	enemy_counter = 0;
	x = 0;
	while (x < fl->map_size_x)
	{
		y = 0;
		while (y < fl->map_size_y)
		{
			if (fl->map[x][y] == PLAYER)
				player_counter++;
			if (fl->map[x][y] == ENEMY)
				enemy_counter++;
			y++;
		}
		x++;
	}
	if (player_counter == 1 && enemy_counter == 0)
		return (TRUE);
	else
		return (FALSE);
}

void		place_token(t_filler *fl, int map_x, int map_y)
{
	int		x;
	int		y;

	x = 0;
	while (x < fl->token_trim_size_x)
	{
		y = 0;
		while (y < fl->token_trim_size_y)
		{
			if (fl->token_trimmed[x][y] == TOKEN
			&& fl->map[map_x + x][map_y + y] == EMPTY)
				fl->map[map_x + x][map_y + y] = TOKEN;
			else if (fl->token_trimmed[x][y] == TOKEN
			&& (fl->map[map_x + x][map_y + y] == fl->player_sign_small
			|| fl->map[map_x + x][map_y + y] == fl->player_sign_big))
				fl->map[map_x + x][map_y + y] = PLAYER;
			else if (fl->token_trimmed[x][y] == TOKEN && \
			(fl->map[map_x + x][map_y + y] == fl->enemy_sign_small ||
			fl->map[map_x + x][map_y + y] == fl->enemy_sign_big))
				fl->map[map_x + x][map_y + y] = ENEMY;
			y++;
		}
		x++;
	}
}

void		locate_enemy(t_filler *fl)
{
	int		x;
	int		y;

	x = 0;
	while (x < fl->map_size_x)
	{
		y = 0;
		while (y < fl->map_size_y)
		{
			if (fl->map[x][y] == fl->enemy_sign_small || \
				fl->map[x][y] == fl->enemy_sign_big)
			{
				fl->enemy_x = x;
				fl->enemy_y = y;
				find_best_distance(fl);
			}
			y++;
		}
		x++;
	}
}

void		solve_filler(t_filler *fl)
{
	int		x;
	int		y;

	x = 0;
	fl->best_x = 1;
	fl->best_y = 1;
	fl->best_solve_distance = 0;
	while (x < fl->map_size_x)
	{
		y = 0;
		while (y < fl->map_size_y)
		{
			if (x + fl->token_trim_size_x <= fl->map_size_x && \
				y + fl->token_trim_size_y <= fl->map_size_y)
				place_token(fl, x, y);
			if (check_solve(fl))
			{
				fl->solve_x = x;
				fl->solve_y = y;
				locate_enemy(fl);
			}
			clear_map(fl);
			y++;
		}
		x++;
	}
}
