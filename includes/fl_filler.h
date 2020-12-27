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

#ifndef FILLER_FL_FILLER_H
#define FILLER_FL_FILLER_H

# include "../lib/libft/includes/libft.h"

# define PLAYER_ERROR   1
# define MALLOC_ERROR	2
# define ENEMY			0
# define PLAYER			-1
# define EMPTY			1
# define MY_FILLER      "fsmith.filler"

typedef struct		s_filler
{
	int				map_s_x;
	int				map_s_y;
	int				piece_s_x;
	int				piece_s_y;
	int				trim_s_x;
	int				trim_s_y;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	char			**map;
	char			**piece;
	char			**piece_trimmed;
	int				map_fd;
	int				solve_x;
	int				solve_y;
	int				enemy_x;
	int				enemy_y;
	int				best_x;
	int				best_y;
	unsigned int	best_solve_distance;
	char			player;
	char			enemy;
}					t_filler;

void				ft_delmap(char **map);
int					ft_nsize(int i);
void				measure_piece(t_filler *filler);
void				clear_map(t_filler *filler);
void				is_best_distance(t_filler *filler);

void				fill_map(t_filler *filler);
void				make_map(t_filler *filler, char *line);
void				fill_piece(t_filler *filler);
void				make_piece(t_filler *filler);
void				trim_piece(t_filler *filler);

int					check_solve(t_filler *filler);
void				place_piece(t_filler *filler, int map_x, int map_y);
void				locate_enemy(t_filler *filler);
void				solve_filler(t_filler *filler);

void				init_player(t_filler *filler, char **line);

void	util_malloc_error(char *str);

#endif
