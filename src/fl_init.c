/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:30:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_filler.h"

void init_player(t_filler *fl)
{
	char		*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "p2"))
	{
		fl->player_sign_small = 'x';
		fl->player_sign_big = 'X';
		fl->enemy_sign_small = 'o';
		fl->enemy_sign_big = 'O';
	}
	else
	{
		fl->player_sign_small = 'o';
		fl->player_sign_big = 'O';
		fl->enemy_sign_small = 'x';
		fl->enemy_sign_big = 'X';
	}
	free(line);
}

void	init_map(t_filler *fl)
{
	int x;

	fl->map = malloc(sizeof(char *) * fl->map_size_x + 1);
	fl->map[fl->map_size_x] = NULL;
	x = 0;
	while (x < fl->map_size_x)
	{
		if ((fl->map[x] = malloc(sizeof(char) * fl->map_size_y + 1)) == NULL)
			util_malloc_error("map");
		fl->map[x][fl->map_size_y] = '\0';
		ft_memset(fl->map[x], '.', fl->map_size_y);
		x++;
	}
}

void	init_token(t_filler *fl)
{
	int		x;

	fl->token = malloc(sizeof(char *) * fl->token_size_x + 1);
	fl->token[fl->token_size_x] = NULL;
	x = 0;
	while (x < fl->token_size_x)
	{
		if ((fl->token[x] = malloc(sizeof(char) * fl->token_size_y + 1)) == NULL)
			util_malloc_error("token");
		fl->token[x][fl->token_size_y] = '\0';
		ft_memset(fl->token[x], '.', fl->token_size_y);
		x++;
	}
}

void	init_trim_token(t_filler *fl)
{
	int		x;
	int		y;

	fl->token_trimmed = malloc(sizeof(char *) * fl->token_trim_size_x + 1);
	fl->token_trimmed[fl->token_trim_size_x] = NULL;
	x = 0;
	while (x < fl->token_trim_size_x)
	{
		y = 0;
		if ((fl->token_trimmed[x] = malloc(sizeof(char) * fl->token_trim_size_y + 1)) == NULL)
			util_malloc_error("trim token");
		fl->token_trimmed[x][fl->token_trim_size_y] = '\0';
		while (y < fl->token_trim_size_y)
		{
			fl->token_trimmed[x][y] =
					fl->token[x + fl->token_start_x][y + fl->token_start_y];
			y++;
		}
		x++;
	}
}
