/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolhas- <mrolhas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:32:53 by mrolhas-          #+#    #+#             */
/*   Updated: 2023/05/21 20:13:41 by mrolhas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = ft_strjoin(0, buff);
	if (ft_clean(buff) > 0)
		return (next_line);
	i = read(fd, buff, BUFFER_SIZE);
	if (i < 0)
	{
		free(next_line);
		return (NULL);
	}
	while (i > 0)
	{
		next_line = ft_strjoin(next_line, buff);
		if (ft_clean(buff) > 0)
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (next_line);
}
