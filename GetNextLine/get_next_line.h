/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:59:17 by fkandler          #+#    #+#             */
/*   Updated: 2025/06/26 12:58:57 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42


char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*read_file(char *line, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
#endif