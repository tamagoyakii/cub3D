/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:00:16 by jabae             #+#    #+#             */
/*   Updated: 2022/11/26 16:23:40 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "../libs/libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define READ_EOF 0
# define READ_SUCCESS 1

char	*get_next_line(int fd);

char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);

#endif