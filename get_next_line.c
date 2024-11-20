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

char *ft_strjoin(const char *s1, const char *s2);

/* char *ft_strjoin(const char *s1, const char *s2)
{
    char *result;
    size_t len1;
    size_t len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	
    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    strcpy(result, s1);
    strcat(result, s2);
    return (result);
} */

 char *get_next_line(int fd)
{
    static char *remainder;
    char *buffer;
    char *line;
    char *temp;
    char *newline_pos;
    int bytes_read;
     printf("aqui =======");


    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    if (!remainder)
        remainder = ft_strdup("");

      printf("aqui =======");

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
       /*  printf("\nbuffer %s ", buffer); */
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(remainder, buffer);
        /* printf("Remainder%i => %s\n", count_remainder, remainder);
        count_remainder += 1; */

        //verificar se com o if esta lidando apenas com a primeira ocorrecia de \n 
        if ((newline_pos = strchr(remainder, '\n')))
        {
            *newline_pos = '\0';
            line = ft_strdup(remainder);

           /*  printf("Remainder%i => %s\n", count_remainder, remainder);
            count_remainder += 1; */


            temp = ft_strdup(newline_pos + 1);
            free(remainder);
            remainder = temp;
            free(buffer);
            return (line);
        }

        /*  while ((newline_pos = strchr(remainder, '\n')))
        {
            *newline_pos = '\0';
            line = strdup(remainder);
            temp = strdup(newline_pos + 1);
             printf("Remainder%i => %s\n", count_remainder, remainder);
            count_remainder += 1;
            free(remainder);
            remainder = temp;
            free(buffer);
            return (line);                
        } */
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