/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:31:30 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/13 21:13:04 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <fcntl.h>    // open()
#include <unistd.h>   // read(), write(), close()
#include <stdio.h>    // colocar a minha printf()
#include <stdlib.h>   // malloc(), free()





char	*get_next_line(int fd);
char	*strjoin(char *s1, char *s2);

# endif