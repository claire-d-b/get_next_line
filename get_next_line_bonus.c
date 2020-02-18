/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 08:19:19 by clde-ber          #+#    #+#             */
/*   Updated: 2020/02/07 10:43:16 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*ft_read_a_join(size_t i, char *buf, char **line)
{
	buf[i] = '\0';
	line[0] = join_a_free(line[0], buf);
	return (line[0]);
}

static char		*ft_update_left(char *left, char *buf, char **line)
{
	line[0][find_n(line[0], ft_strlen(line[0]))] = '\0';
	ft_memmove(left, buf + find_n(buf, BUFFER_SIZE) + 1, ft_strlen(buf +
	find_n(buf, BUFFER_SIZE)) + 1);
	return (line[0]);
}

static char		*ft_create_a_clear_left(char *left, size_t size)
{
	int k;

	if (left)
	{
		k = find_n(left, size);
		if (k != -1)
			ft_memmove(left, left + k + 1, ft_strlen(left + k) + 1);
		else
			left[0] = '\0';
		return (left);
	}
	else
	{
		if (!(left = malloc(sizeof(char) * (size + 1))))
			return (0);
		left[0] = '\0';
		return (left);
	}
}

int				get_next_line(int fd, char **line)
{
	ssize_t		i;
	char		buf[BUFFER_SIZE + 1];
	static char *left;

	buf[0] = '\0';
	left = (!left) ? ft_create_a_clear_left(left, BUFFER_SIZE) : left;
	line[0] = ft_strjoin(left, "");
	ft_create_a_clear_left(left, BUFFER_SIZE);
	if (find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0][find_n(line[0], ft_strlen(line[0]))] = '\0';
		return (1);
	}
	while (find_n(buf, BUFFER_SIZE) == -1 &&
	(i = read(fd, buf, BUFFER_SIZE)) > 0)
		line[0] = ft_read_a_join(i, buf, line);
	line[0] = (i == 0) ? line[0] : join_a_free(line[0], buf);
	if (find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0] = ft_update_left(left, buf, line);
		return (1);
	}
	free(left);
	left = 0;
	return (fd < 0 || read(fd, buf, 0) < 0 || BUFFER_SIZE <= 0) ? -1 : 0;
}
