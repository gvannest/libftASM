#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

char *ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, char *s2);

int     main(void)
{
    // char *str = "Hello World!";
    // printf("len de '%s' : %d\n\n", str, ft_strlen(str));

    char    *str1 = "bonjour gautier!";
    char    *cmp1 = "bonjour gautier!";

    printf("Ma strcmp asm : '%d'\n", ft_strcmp(str1, cmp1));
    printf("La strcmp libC '%d'\n", strcmp(str1, cmp1));
	if (ft_strcmp(str1, cmp1) == strcmp(str1, cmp1))
		printf(COLOR_GREEN"OK\n"COLOR_RESET);
	else
		printf(COLOR_RED"FAILED\n"COLOR_RESET);
	printf("-----------------------------\n");

    char    *str2 = "bongour gautier!";
    char    *cmp2 = "bonjour gautier!";

    printf("Ma strcmp asm : '%d'\n", ft_strcmp(str2, cmp2));
    printf("La strcmp libC '%d'\n", strcmp(str2, cmp2));
	if (ft_strcmp(str2, cmp2) == strcmp(str2, cmp2))
		printf(COLOR_GREEN"OK\n"COLOR_RESET);
	else
		printf(COLOR_RED"FAILED\n"COLOR_RESET);
	printf("-----------------------------\n");

    char    *str3 = "";
    char    *cmp3 = "bonjour gautier!";

    printf("Ma strcmp asm : '%d'\n", ft_strcmp(str3, cmp3));
    printf("La strcmp libC '%d'\n", strcmp(str3, cmp3));
	if (ft_strcmp(str3, cmp3) == strcmp(str3, cmp3))
		printf(COLOR_GREEN"OK\n"COLOR_RESET);
	else
		printf(COLOR_RED"FAILED\n"COLOR_RESET);
	printf("-----------------------------\n");

    char    *str4 = "bongour gautier!";
    char    *cmp4 = "";

    printf("Ma strcmp asm : '%d'\n", ft_strcmp(str4, cmp4));
    printf("La strcmp libC '%d'\n", strcmp(str4, cmp4));
	if (ft_strcmp(str4, cmp4) == strcmp(str4, cmp4))
		printf(COLOR_GREEN"OK\n"COLOR_RESET);
	else
		printf(COLOR_RED"FAILED\n"COLOR_RESET);
	printf("-----------------------------\n");

    return (0);
}
