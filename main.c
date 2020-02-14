#include <stdlib.h>
#include <stdio.h>

char *ft_strcpy(char *dst, const char *src);

int     main(void)
{
    // char *str = "Hello World!";
    // printf("len de '%s' : %d\n\n", str, ft_strlen(str));

    char    *dst = NULL;
    char    *src = "bonjour gautier!";

    dst = (char*)malloc(0x20);
    dst = ft_strcpy(dst, src);
    printf("le pointeur dst en sortie '%p'\n", dst);
    printf("la string en destination '%s'\n", dst);

    return (0);
}