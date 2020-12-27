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

void	ft_delmap(char **map)
{
	int				y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

int		ft_nsize(int i)
{
	int				len;

	len = 1;
	while (i /= 10)
		len++;
	return (len);
}

void	measure_piece(t_filler *filler)
{
	int				x;
	int				y;

	x = 0;
	filler->start_x = -1;
	filler->start_y = filler->piece_s_y;
	filler->end_y = -1;
	while (x < filler->piece_s_x)
	{
		y = 0;
		while (y < filler->piece_s_y)
		{
			if (filler->piece[x][y] != '.' && filler->start_x == -1)
				filler->start_x = x;
			if (filler->piece[x][y] != '.' && y < filler->start_y)
				filler->start_y = y;
			if (filler->piece[x][y] != '.')
				filler->end_x = x;
			if (filler->piece[x][y] != '.' && y > filler->end_y)
				filler->end_y = y;
			y++;
		}
		x++;
	}
}

void	clear_map(t_filler *filler)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (x < filler->map_s_x)
	{
		y = 0;
		while (y < filler->map_s_y)
		{
			if (filler->map[x][y] == 'A')
				filler->map[x][y] = filler->player;
			if (filler->map[x][y] == 'B')
				filler->map[x][y] = filler->enemy;
			if (filler->map[x][y] == '*')
				filler->map[x][y] = '.';
			y++;
		}
		x++;
	}
}

void	is_best_distance(t_filler *filler)
{
	int				x;
	int				y;
	unsigned int	distance;

	x = filler->enemy_x - filler->solve_x - filler->trim_s_x / 2;
	y = filler->enemy_y - filler->solve_y - filler->trim_s_y / 2;
	distance = ((x * x) + (y * y));
	if (distance < filler->best_solve_distance ||\
		filler->best_solve_distance == 0)
	{
		filler->best_x = filler->solve_x;
		filler->best_y = filler->solve_y;
		filler->best_solve_distance = distance;
	}
}
