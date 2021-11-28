/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:23:30 by ael-asri          #+#    #+#             */
/*   Updated: 2021/11/28 10:38:23 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char	*s);
size_t	ft_strlen(const char	*s);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);
char	*ft_strdup(char *s1);

#endif
