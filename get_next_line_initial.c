/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:31:30 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/20 01:47:02 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h> 



 char *get_next_line(int fd)
{
    static char *remainder;
    char *buffer;
    char *line;
    char *temp;
    char *newline_pos;
    int bytes_read;


    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    if (!remainder)
        remainder = ft_strdup("");


    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(remainder, buffer);
        free(remainder);
        remainder = temp;
        while ((newline_pos = strchr(remainder, '\n')))
        {
            *newline_pos = '\0';
            line = ft_strdup(remainder);
            temp = ft_strdup(newline_pos + 1);
            free(remainder);
            remainder = temp;
            free(buffer);
            
            if (*line == '\0')
            {
                free(line);
                return (line);
            }
            return (line);
        }
    }

    free(buffer);
    if (bytes_read < 0 || !remainder || !*remainder)
    {
        free(remainder);
        remainder = NULL;
        return (NULL);
    }

    line = ft_strdup(remainder);
    free(remainder);
    remainder = NULL;
    return (line);
}