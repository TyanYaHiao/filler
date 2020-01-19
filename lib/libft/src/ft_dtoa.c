/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:19:04 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/24 20:32:00 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_dtoa(double n, size_t precision)
{
	char	*str;

	if (n < 0 && n > -1)
		str = ft_strcat(ft_strdup("-"), ft_itoa((int)n));
	else
		str = ft_itoa((int)n);
	if (precision > 0)
	{
		str = ft_strcat(str, ".");
		str = ft_strcat(str, ft_itoa(ft_abs((int)(n * ft_power(10, precision))
		% ft_power(10, precision))));
	}
	return (str);
}
