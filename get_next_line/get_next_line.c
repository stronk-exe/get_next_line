/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:53:10 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/26 22:30:56 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char	*line)
{
	int		i;
	int		j;
	int		t;
	char	*temp;
	char	*chyata;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * ft_strlen(line));
	while (line[i] != '\n')
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = line[i];
	i++;
	t = i;
	while (line[t])
	{
		t++;
	}
	chyata = malloc(sizeof(char) * (t - i));
	while (line[i])
	{
		chyata[j] = line[i];
		i++;
		j++;
	}
	free(line);
	line = chyata;
	return (temp);
}

char	*read_line(int fd, char *line)
{
	char	*buffer;
	ssize_t		n;

	n = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr(line, '\n') == 0 && n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (get_line(line));
	//return(line);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*buffer;
	char			*buffer_read;

	if (fd <= 0)
		return (NULL);
	return (read_line(fd, buffer));
}



#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("test.txt", O_RDWR);
	
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
}