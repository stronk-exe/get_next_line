/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:22:44 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/28 14:26:52 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_chyata_bonus(char *line)
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

char	*get_line_bonus(char	*line)
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

char	*read_line_bonus(int fd, char *line)
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

char	*get_next_line_bonus(int fd)
{
   // static char *line[FOPEN_MAX];
	//static char		*line;
	char			*buffer;

	if (fd <= 0)
		return (NULL);
	line[fd] = read_line_bonus(fd, line[fd]);
	buffer = get_line_bonus(line[fd]);
	line[fd] = get_chyata_bonus(line[fd]);
	return (buffer);
}
