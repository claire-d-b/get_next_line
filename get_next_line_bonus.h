/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 08:19:50 by clde-ber          #+#    #+#             */
/*   Updated: 2020/02/07 10:46:36 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*join_a_free(char *s1, char *s2);
size_t		ft_strlen(char *str);
int			find_n(char *buf, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strjoin(char *s1, char *s2);

#endif
