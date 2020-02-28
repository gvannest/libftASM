#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

char    *ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, char *s2);
size_t  ft_write(int fildes, const void *buf, size_t nbyte);
size_t  ft_read(int fildes, void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);

int     main(void)
{
    // char *str = "Hello World!";
    // printf("len de '%s' : %d\n\n", str, ft_strlen(str));

    char    *str1 = "bonjour gautier!";
    char    *cmp1 = "bonjour gautier!";

    printf("Ma strcmp asm : %d\n", ft_strcmp(str1, cmp1));
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


    char *str_w1 = "je veux ecrire ca\n";
    char *str_w2 = "";
    char *str_w3 = "l";
    char *str_w4 = "Salut c'est gvann!\n\n";

    ft_write(1, str_w1, 18);
    ft_write(1, str_w2, 0);
    ft_write(1, str_w3, 1);
    ft_write(1, str_w4, 20);

    char *path_1 = "./tests/test_1.txt";
    char *path_2 = "./tests/test_2.txt";
    char *path_3 = "./tests/test_3.txt";

    int fd1 = open(path_1, O_RDWR | O_CREAT);
    int fd2 = open(path_2, O_RDWR | O_CREAT);
    int fd3 = open(path_3, O_RDWR | O_CREAT);

    char buf1[100]; 
    char buf2[100]; 
    char buf3[100]; 

    ft_read(fd1, buf1, 100);
    ft_read(fd2, buf2, 100);
    ft_read(fd3, buf3, 100);

    printf("buf1 : %s\n", buf1);
    printf("buf2 : %s\n", buf2);
    printf("buf3 : %s\n", buf3);

    char *dup_1 = "C'est joli!\n";
    char *dup_2 = "Hello moi c gvann, ca gaz?";
    char *dup_3 = "On va teter un truc bien bien plus long et bien relou Wesh\n";
    char *dup_4 = "";
    printf("Ceci est un retour de ma fonction ft_strdup : %s\n", ft_strdup(dup_1));
    printf("Ceci est un retour de ma fonction ft_strdup : %s\n", ft_strdup(dup_2));
    printf("Ceci est un retour de ma fonction ft_strdup : %s\n", ft_strdup(dup_3));
    printf("Ceci est un retour de ma fonction ft_strdup : %s\n", ft_strdup(dup_4));


    return (0);
}
