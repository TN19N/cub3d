/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:30:12 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 11:00:49 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#define BUFFER_SIZE 1

int	if_is_ther(char *saver)
{
	if (!saver)
		return (0);
	while (*saver)
	{
		if (*saver == '\n')
			return (1);
		saver++;
	}
	return (0);
}

char	*get_fill(int fd, char *line)
{
	char		*buff;
	int			i;
	char 		*tmp;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		ft_error("malloc failed :(\n");;
	i = 1;
	while (!if_is_ther(line) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
	}
	free(buff);
	return (line);
}

char	*ft_get_line(int fd)
{
	char		*line;

	line == NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_fill(fd, line);
	if (!line)
		return (NULL);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
