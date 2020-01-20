/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:30:27 by fsmith            #+#    #+#             */
/*   Updated: 2019/07/28 16:13:47 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include "libft.h"

# define PLAYER_ERROR   1
# define MALLOC_ERROR	2
# define ENEMY			0
# define PLAYER			-1
# define EMPTY			1
# define MY_FILLER      "fsmith.filler"

typedef	struct	s_filler
{
    int			x;
    int			y;
    int			*map;
    int			x_size;
    int			y_size;
    char		player;
    char		dot_small;
    char		dot_big;
    char		enemy_dot_small;
    char		enemy_dot_big;
    int			real_piece_x_size;
    int			real_piece_y_size;
    int			piece_x_size;
    int			piece_y_size;
    int			*piece;
}				t_filler;

void fl_player_parser(t_filler *filler);
void fl_game_loop(t_filler *filler);
int fl_find_size(t_filler *filler);
void fl_parse_map(t_filler *filler);
void fl_zero_map(t_filler *filler);
int fl_parse_piece_size(t_filler *filler);
void fl_parse_piece(t_filler *filler);

void 	fl_player_errors_handler(t_filler *filler);
void	fl_util_malloc_error(char *str);

void	util_release_char_matrix(char **mtrx);

#endif //FILLER_FILLER_H
