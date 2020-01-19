/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:39 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/24 20:32:00 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			gnl_extend_line(int fd, char **line1)
{
	char			*line2;
	char			*temp;
	ssize_t			read_len;

	line2 = ft_strnew(BUFF_SIZE);
	read_len = read(fd, line2, BUFF_SIZE);
	if (read_len == 0)
	{
		free(line2);
		return (0);
	}
	line2[read_len] = '\0';
	temp = ft_strdup(*line1);
	free(*line1);
	*line1 = ft_strjoin(temp, line2);
	free(temp);
	free(line2);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*line1[MAX_FD];

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0 || fd > MAX_FD)
		return (-1);
	if (!line1[fd])
	{
		line1[fd] = ft_strnew(BUFF_SIZE);
		line1[fd][read(fd, line1[fd], BUFF_SIZE)] = '\0';
	}
	while (!ft_strchr(line1[fd], '\n'))
	{
		if (gnl_extend_line(fd, &line1[fd]) == 0)
		{
			if (*line == line1[fd])
				return (0);
			*line = line1[fd];
			if (ft_strcmp(*line, "") == 0)
				return (0);
			return (1);
		}
	}
	*line = ft_strcut(&line1[fd], '\n');
	return (1);
}

//static char *ft_strsave(char *str1, char *str2)
//{
//    char	*str3;
//
//    if (!str1 && !str2)
//        return (NULL);
//    if (!str1)
//        return (ft_strdup(str2));
//    if (!str2)
//        return (ft_strdup(str1));
//    if (!(str3 = malloc(sizeof(*str3) *
//                        (ft_strlen(str1) + ft_strlen(str2) + 1))))
//        return (NULL);
//    ft_strcpy(str3, (char *)str1);
//    ft_strcat(str3, (char *)str2);
//    ft_memdel((void *)&str1);
//    return (str3);
//}
//
//int		    get_next_line(const int fd, char **line)
//{
//    static char *c[10000] = {NULL};
//    char		buf[BUFF_SIZE + 1];
//    int			shift;
//    int			n;
//    char		*s;
//
//    if ((shift = (fd < 0 || !line)))
//        return (-1);
//    while (!(s = ft_strchr(c[fd] + (shift += !shift ? 0 : n), '\n')))
//    {
//        if ((n = read(fd, buf, BUFF_SIZE)) <= 0)
//            break ;
//        buf[n] = '\0';
//        if (!(c[fd] = ft_strsave(c[fd], buf)))
//            return (-1);
//    }
//    if ((!c[fd] && !n) || n < 0 || !*c[fd])
//        return (n < 0 ? -1 : 0);
//    n = s ? (s - c[fd]) : ft_strlen(c[fd]);
//    if (!(*line = ft_strnew(n)) & !ft_strncpy(*line, c[fd], n))
//        return (-1);
//    s = s ? ft_strdup(s + 1) : NULL;
//    ft_memdel((void *)&c[fd]);
//    return ((c[fd] = s) == s);
//}