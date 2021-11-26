/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:53:55 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/26 20:09:26 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const	*s1, char const	*s2);
int		ft_strchr(char	*s, char c);
size_t	ft_strlen(const char	*s);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);

#endif
