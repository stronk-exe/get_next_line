/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:53:10 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/28 00:46:52 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
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
		buffer[n] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*buffer;

	if (fd <= 0)
		return (NULL);
	line = read_line(fd, line);
	buffer = get_line(line);
	line = get_chyata(line);
	return (buffer);
}
