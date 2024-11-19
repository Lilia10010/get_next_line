#include "get_next_line.h"

char *test_strjoin(const char *s1, const char *s2)
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