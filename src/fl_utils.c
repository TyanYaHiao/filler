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

#include	"filler.h"

void		util_release_char_matrix(char **mtrx)
{
	int		i;

	i = 0;
	while (mtrx[i] != NULL)
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}