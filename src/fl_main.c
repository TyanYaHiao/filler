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

#include "filler.h"

int main()
{
	t_filler filler;

	fl_player_parser(&filler);
//	fl_game_loop(&filler);
	fl_find_size(&filler);
	fl_parse_map(&filler);
	fl_parse_piece_size(&filler);
	fl_parse_piece(&filler);
	return 0;
}

void fl_game_loop(t_filler *filler)
{
	while (1)
	{
		if (!fl_find_size(filler))
			break ;
	}
}

void fl_zero_map(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->x_size * filler->y_size)
	{
		filler->map[i] = EMPTY;
		i++;
	}
}

void fl_parse_piece(t_filler *filler)
{
	// остановился здесь. нужно думать как считать фигуру, как ее записать и как примерять установку на поле.
	char	*str;
	char	**splitted_line;
	int 	i;
	int		counter;

	counter = 0;
	fl_zero_map(filler);
	while(get_next_line(0, &str) && counter < filler->piece_x_size * filler->piece_y_size)
	{
		splitted_line = ft_strsplitwhitespaces(str);
		if (splitted_line[0] && !splitted_line[1] && ft_strlen(splitted_line[0]) == filler->piece_x_size)
		{
			i = 0;
			while(splitted_line[0][i])
			{
				if (splitted_line[1][i] == filler->dot_small || splitted_line[1][i] == filler->dot_big)
					filler->map[ft_atoi(splitted_line[0]) * filler->x_size + i] = PLAYER;
				else if (splitted_line[1][i] == filler->enemy_dot_small || splitted_line[1][i] == filler->enemy_dot_big)
					filler->map[ft_atoi(splitted_line[0]) * filler->x_size + i] = ENEMY;
				i++;
				counter++;
			}
		}
		util_release_char_matrix(splitted_line);
	}
//	int j = 0;
//	while (j < filler->x_size * filler->y_size)
//	{
//		ft_putstr_fd(ft_itoa(filler->map[j]), 2);
//		j++;
//	}
}

int fl_parse_piece_size(t_filler *filler)
{
	char *str;
	char **splitted_line;
	int counter;

	counter = 0;
	fl_zero_map(filler);
	while (get_next_line(0, &str) && counter < filler->x_size * filler->y_size)
	{
		if (!ft_strncmp(str, "Piece ", 6))
		{
			splitted_line = ft_strsplitwhitespaces(str);
			filler->piece_y_size = ft_atoi(splitted_line[1]);
			filler->piece_x_size = ft_atoi(splitted_line[2]);
			util_release_char_matrix(splitted_line);
			return (0);
		}
	}
	return (1);
}

void fl_parse_map(t_filler *filler)
{
	char	*str;
	char	**splitted_line;
	int 	i;
	int		counter;

	counter = 0;
	fl_zero_map(filler);
	while(get_next_line(0, &str) && counter < filler->x_size * filler->y_size)
	{
		splitted_line = ft_strsplitwhitespaces(str);
		if (splitted_line[0] && splitted_line[1] && !splitted_line[2] && ft_strlen(splitted_line[0]) == 3 && ft_strlen(splitted_line[1]) == filler->x_size)
		{
			i = 0;
			while(splitted_line[1][i])
			{
				if (splitted_line[1][i] == filler->dot_small || splitted_line[1][i] == filler->dot_big)
					filler->map[ft_atoi(splitted_line[0]) * filler->x_size + i] = PLAYER;
				else if (splitted_line[1][i] == filler->enemy_dot_small || splitted_line[1][i] == filler->enemy_dot_big)
					filler->map[ft_atoi(splitted_line[0]) * filler->x_size + i] = ENEMY;
				i++;
				counter++;
			}
		}
		util_release_char_matrix(splitted_line);
	}
//	int j = 0;
//	while (j < filler->x_size * filler->y_size)
//	{
//		ft_putstr_fd(ft_itoa(filler->map[j]), 2);
//		j++;
//	}
}

int fl_find_size(t_filler *filler)
{
	char	*str;
	char	**splitted_line;

	while(get_next_line(0, &str))
	{
		if (!ft_strncmp(str, "Plateau ", 8))
		{
			splitted_line = ft_strsplitwhitespaces(str);
			filler->y_size = ft_atoi(splitted_line[1]);
			filler->x_size = ft_atoi(splitted_line[2]);
			if ((filler->map = (int *)ft_memalloc(
					sizeof(int) * filler->x_size * filler->y_size)) == NULL)
				fl_util_malloc_error("filler->map");
//			ft_putstr_fd("--Map size: ", 2);
//			ft_putstr_fd("x: ", 2);
//			ft_putstr_fd(ft_itoa(filler->x_size), 2);
//			ft_putstr_fd(" y: ", 2);
//			ft_putstr_fd(ft_itoa(filler->y_size), 2);
//			ft_putstr_fd("--\n", 2);
			util_release_char_matrix(splitted_line);
			return 0;
		}
//		ft_putendl_fd("!", 2);
	}
	return 1;
}
