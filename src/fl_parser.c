/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:30:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_filler.h"

void	fill_map(t_filler *fl)
{
	int		x;
	int		y;
	char	*line;

	get_next_line(0, &line);
	free(line);
	x = 0;
	while (x < fl->map_size_x)
	{
		y = 0;
		get_next_line(0, &line);
		while (y < fl->map_size_y)
		{
			if (line[y + SHIFT] != '.')
				fl->map[x][y] = line[y + SHIFT];
			y++;
		}
		free(line);
		x++;
	}
}

void	parse_map(t_filler *fl, char *line)
{
	free(line);
	fl->map_size_x = ft_atoi(&line[8]);
	fl->map_size_y = ft_atoi(&line[8 + ft_nbrlen(fl->map_size_x)]);
	init_map(fl);
	fill_map(fl);
}

void	fill_token(t_filler *fl)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	while (x < fl->token_size_x)
	{
		y = 0;
		get_next_line(0, &line);
		while (y < fl->token_size_y)
		{
			if (line[y] == '*')
				fl->token[x][y] = '*';
			y++;
		}
		free(line);
		x++;
	}
}

void	parce_token(t_filler *fl)
{
	char	*line;

	get_next_line(0, &line);
	fl->token_size_x = ft_atoi(&line[6]);
	fl->token_size_y = ft_atoi(&line[6 + ft_nbrlen(fl->token_size_x)]);
	free(line);
	init_token(fl);
	fill_token(fl);
}

void	trim_token(t_filler *fl)
{
	measure_token(fl);
	fl->token_trim_size_x = (fl->token_end_x - fl->token_start_x) + 1;
	fl->token_trim_size_y = (fl->token_end_y - fl->token_start_y) + 1;
	init_trim_token(fl);
}
