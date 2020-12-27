/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:30:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "fl_filler.h"

void	free_maps(t_filler *fl)
{
	ft_clear_2d_array(fl->map);
	ft_clear_2d_array(fl->token);
	ft_clear_2d_array(fl->token_trimmed);
}

void	measure_token(t_filler *fl)
{
	int				x;
	int				y;

	fl->token_start_x = -1;
	fl->token_start_y = fl->token_size_y;
	fl->token_end_y = -1;
	x = 0;
	while (x < fl->token_size_x)
	{
		y = 0;
		while (y < fl->token_size_y)
		{
			if (fl->token[x][y] != EMPTY && fl->token_start_x == -1)
				fl->token_start_x = x;
			if (fl->token[x][y] != EMPTY && y < fl->token_start_y)
				fl->token_start_y = y;
			if (fl->token[x][y] != EMPTY)
				fl->token_end_x = x;
			if (fl->token[x][y] != EMPTY && y > fl->token_end_y)
				fl->token_end_y = y;
			y++;
		}
		x++;
	}
}

void	clear_map(t_filler *fl)
{
	int				x;
	int				y;

	x = 0;
	while (x < fl->map_size_x)
	{
		y = 0;
		while (y < fl->map_size_y)
		{
			if (fl->map[x][y] == PLAYER)
				fl->map[x][y] = fl->player_sign_small;
			if (fl->map[x][y] == ENEMY)
				fl->map[x][y] = fl->enemy_sign_small;
			if (fl->map[x][y] == TOKEN)
				fl->map[x][y] = EMPTY;
			y++;
		}
		x++;
	}
}

void	find_best_distance(t_filler *fl)
{
	int				x;
	int				y;
	unsigned int	distance;

	x = fl->enemy_x - fl->solve_x - fl->token_trim_size_x / 2;
	y = fl->enemy_y - fl->solve_y - fl->token_trim_size_y / 2;
	distance = ((x * x) + (y * y));
	if (distance < fl->best_solve_distance || fl->best_solve_distance == 0)
	{
		fl->best_x = fl->solve_x;
		fl->best_y = fl->solve_y;
		fl->best_solve_distance = distance;
	}
}

void	make_move(t_filler *fl)
{
	ft_putnbr(fl->best_x - fl->token_start_x);
	ft_putchar(' ');
	ft_putnbr(fl->best_y - fl->token_start_y);
	ft_putchar('\n');
}