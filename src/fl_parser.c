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

#include	"filler.h"

int			fl_player_parser(t_filler *filler)
{
	char	*str;
	int		len;

	str = NULL;
	get_next_line(0, &str);
	len = ft_strlen(str);
	if (ft_strncmp(str, "$$$ exec p", 10) || len < 16 + ft_strlen(MY_FILLER))
		return (0);
	if (!ft_strncmp(str + len - ft_strlen(MY_FILLER) - 1, MY_FILLER,
			ft_strlen(MY_FILLER)))
		filler->player = str[10];
	return (0);
}
