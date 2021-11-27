/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:53:10 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/27 22:21:56 by ael-asri         ###   ########.fr       */
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
	temp = ft_substr(line, 0, i + 1);
	free(line);
	line = NULL;
	return (temp);
}

char	*read_line(int fd, /*char *buffer,*/ char *line)
{
	char		*buffer;
	ssize_t		n;


	int i = 0;


	n = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer = ft_strdup("");
	if (!line)
		line = ft_strdup("");
//	printf("chyata remi %s>>\n", line);
//	printf("joinin0000-%s\n", line);
	while (ft_strchr(line) == 0 && n != 0)
	{
	//	printf("line status %d		%s\n", i,line);
	//	printf("buffer status-%d		%s-\n", i,buffer);
		n = read(fd, buffer, BUFFER_SIZE);
	//	printf("joinin %d-%s\n", i,line);
		buffer[n] = '\0';
	//	printf("joinin before-%s\n", line);
		line = ft_strjoin(line, buffer);
	//	printf("joinin after-%d		%s-\n", i,line);
		i++;
	}
	free(buffer);
//	printf("kaml %s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*buffer;
	if (fd <= 0 /*|| BUFFER_SIZE > ftell(fd)*/)
		return (NULL);
//	printf("line lwl %s>>\n", line);
	line = read_line(fd, /*buffer,*/ line);
//	printf("main lmkh %s\n", line);
	buffer = get_line(line);
//	printf("main buff %s\n", buffer);
//	printf("main lmkh22 %s\n", line);
	line = get_chyata(line);

//	printf("chyata line %s>>\n", line);
	return (buffer);
}



#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("test.txt", O_RDWR);
	system("leaks a.out");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	system("leaks a.out");
}