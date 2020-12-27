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

void	fill_map(t_filler *filler)
{
	int		x;
	int		offset;
	char	*line;

	x = 0;
	get_next_line(0, &line);
	free(line);
	while (x < filler->map_s_x)
	{
		offset = 4;
		get_next_line(0, &line);
		while (offset < filler->map_s_y + 4)
		{
			if (line[offset] != '.')
				filler->map[x][offset - 4] = line[offset];
			offset++;
		}
		free(line);
		x++;
	}
}

void	make_map(t_filler *filler, char *line)
{
	int		x;

	x = 0;
	filler->map_s_x = ft_atoi(&line[8]);
	filler->map_s_y = ft_atoi(&line[8 + ft_nsize(filler->map_s_x)]);
	filler->map = malloc(sizeof(char *) * filler->map_s_x + 1);
	filler->map[filler->map_s_x] = NULL;
	while (x < filler->map_s_x)
	{
		filler->map[x] = malloc(sizeof(char) * filler->map_s_y + 1);
		filler->map[x][filler->map_s_y] = '\0';
		ft_memset(filler->map[x], '.', filler->map_s_y);
		x++;
	}
	fill_map(filler);
}

void	fill_piece(t_filler *filler)
{
	int		x;
	int		offset;
	char	*line;

	x = 0;
	while (x < filler->piece_s_x)
	{
		offset = 0;
		get_next_line(0, &line);
		while (offset < filler->piece_s_y)
		{
			if (line[offset] == '*')
				filler->piece[x][offset] = '*';
			offset++;
		}
		free(line);
		x++;
	}
}

void	make_piece(t_filler *filler)
{
	int		x;
	char	*line;

	x = 0;
	get_next_line(0, &line);
	filler->piece_s_x = ft_atoi(&line[6]);
	filler->piece_s_y = ft_atoi(&line[6 + ft_nsize(filler->piece_s_x)]);
	filler->piece = malloc(sizeof(char *) * filler->piece_s_x + 1);
	filler->piece[filler->piece_s_x] = NULL;
	while (x < filler->piece_s_x)
	{
		filler->piece[x] = malloc(sizeof(char) * filler->piece_s_y + 1);
		filler->piece[x][filler->piece_s_y] = '\0';
		ft_memset(filler->piece[x], '.', filler->piece_s_y);
		x++;
	}
	free(line);
	fill_piece(filler);
}

void	trim_piece(t_filler *filler)
{
	int		x;
	int		y;

	measure_piece(filler);
	x = 0;
	filler->trim_s_x = (filler->end_x - filler->start_x) + 1;
	filler->trim_s_y = (filler->end_y - filler->start_y) + 1;
	filler->piece_trimmed = malloc(sizeof(char *) * filler->trim_s_x + 1);
	filler->piece_trimmed[filler->trim_s_x] = NULL;
	while (x < filler->trim_s_x)
	{
		y = 0;
		filler->piece_trimmed[x] = malloc(sizeof(char) * filler->trim_s_y + 1);
		filler->piece_trimmed[x][filler->trim_s_y] = '\0';
		while (y < filler->trim_s_y)
		{
			filler->piece_trimmed[x][y] =\
			filler->piece[x + filler->start_x][y + filler->start_y];
			y++;
		}
		x++;
	}
}
