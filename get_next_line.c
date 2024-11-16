/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:31:30 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/13 00:39:34 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h> 

static char *test_strjoin(const char *s1, const char *s2)
{
    char *result;
    size_t len1;
    size_t len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = strlen(s1);
	len2 = strlen(s2);
	

    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    strcpy(result, s1);
    strcat(result, s2);
    return (result);
}


/*  char	*get_next_line(int fd)
 {
	char	*line;
	char	*buffer;
	int		bytes_read;

	line = NULL;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	line = test_strjoin(line, buffer);
	free(buffer);
	return (line);
 } */

 char *get_next_line(int fd)
{
    static char *remainder;
    char *buffer;
    char *newline_pos;
    char *line;
    int bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    if (!remainder)
        remainder = strdup("");

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        remainder = test_strjoin(remainder, buffer);
        if ((newline_pos = strchr(remainder, '\n')))
        {
            *newline_pos = '\0';
            line = strdup(remainder);
            remainder = strdup(newline_pos + 1);
            free(buffer);
            return (line);
        }
    }

    free(buffer);
    if (bytes_read == -1 || !*remainder)
    {
        free(remainder);
        remainder = NULL;
        return (NULL);
    }

    line = strdup(remainder);
    free(remainder);
    remainder = NULL;
    return (line);
}