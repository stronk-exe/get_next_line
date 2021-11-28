/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:22:44 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/28 19:17:52 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_chyata(char *line)
{
	char	*chyata;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	chyata = ft_substr(line, i + 1, ft_strlen(line));
	free(line);
	line = NULL;
	return (chyata);
}

char	*get_line(char	*line)
{
	int		i;
	char	*temp;

	i = 0;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	temp = ft_substr(line, 0, i + 1);
	return (temp);
}

char	*read_line(int fd, char *line)
{
	char		*buffer;
	ssize_t		n;

	n = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	while (ft_strchr(line) == 0 && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			free (line);
			return (NULL);
		}
		buffer[n] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line[FOPEN_MAX];
	char			*buffer;

	if (read(fd, "", 0) == -1)
		return (0);
	if (BUFFER_SIZE < 0)
		return (NULL);
	line[fd] = read_line(fd, line[fd]);
	buffer = get_line(line[fd]);
	line[fd] = get_chyata(line[fd]);
	if (buffer == NULL)
		line[fd] = NULL;
	return (buffer);
}
