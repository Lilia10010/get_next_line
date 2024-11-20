#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

/* 
size_t	ft_strlen(const char *str)
{
	size_t length;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
    char	*join;
    size_t	len_s1;
    size_t	len_s2;

    if (!s1 || !s2)
        return (NULL);

    join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!join)
        return (NULL);

    len_s1 = -1;
    while (s1[++len_s1])
    {
        join[len_s1] = s1[len_s1];
    }
        
    len_s2 = -1;
    while (s2[++len_s2])
    {
        join[len_s1 + len_s2] = s2[len_s2];
    }
    join[len_s1 + len_s2] = '\0';
    return (join);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	length;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	length = -1;
	while (str[++length])
		copy[length] = str[length];
	copy[length] = '\0';
	return (copy);
}
 */

int main(void)
{
	char	*s1 = "hello";
	char	*dest;

	dest = ft_strdup(s1);
	printf("duplicate = %s", dest);

	free(dest);

	return (0);
}