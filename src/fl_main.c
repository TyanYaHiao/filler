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
