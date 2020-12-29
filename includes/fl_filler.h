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

# define FILLER_FL_FILLER_H

# include "../lib/libft/includes/libft.h"

# define MALLOC_ERROR	1
# define EMPTY			'.'
# define TOKEN			'*'
# define PLAYER			'P'
# define ENEMY			'E'
# define SHIFT			4

typedef struct		s_filler
{
	char			**map;
	char			**token;
	char			**token_trimmed;
	int				map_size_x;
	int				map_size_y;
	int				token_size_x;
	int				token_size_y;
	char			player_sign_small;
	char			player_sign_big;
	char			enemy_sign_small;
	char			enemy_sign_big;
	int				token_trim_size_x;
	int				token_trim_size_y;
	int				token_start_x;
	int				token_start_y;
	int				token_end_x;
	int				token_end_y;
	int				solve_x;
	int				solve_y;
	int				enemy_x;
	int				enemy_y;
	int				best_x;
	int				best_y;
	unsigned int	best_solve_distance;
}					t_filler;

void				ft_clear_2d_array(char **array);
void				free_maps(t_filler *fl);
int					ft_nbrlen(int i);
void				measure_token(t_filler *fl);
void				clear_map(t_filler *fl);
void				find_best_distance(t_filler *fl);
void				make_move(t_filler *fl);
void				fill_map(t_filler *fl);
void				parse_map(t_filler *fl, char *line);
void				fill_token(t_filler *fl);
void				parce_token(t_filler *fl);
void				trim_token(t_filler *fl);
int					check_solve(t_filler *fl);
void				place_token(t_filler *fl, int map_x, int map_y);
void				locate_enemy(t_filler *fl);
void				solve_filler(t_filler *fl);
void				init_player(t_filler *fl);
void				init_map(t_filler *fl);
void				init_token(t_filler *fl);
void				init_trim_token(t_filler *fl);
void				util_malloc_error(char *str);

#endif
