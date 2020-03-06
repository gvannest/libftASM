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

static void test_strcpy()
{
    char    *str[5];
    char    *str_cpy[5];

    str[0] = "bonjour gautier!";
    str[1] = "";
    str[2] = "C'est bon le null en src segfault\n"; // test 0
    str[3] = "hello world!";

    char    str0_cpy[100];
    char    str1_cpy[100];
    char    str2_cpy[100];
    char    str3_cpy[2];

    str_cpy[0] = str1_cpy;
    str_cpy[1] = str1_cpy;
    str_cpy[2] = str2_cpy;
    str_cpy[3] = str3_cpy; // mettre 0

    for(int i = 0; i < 4; i++){
        printf("Copy de str : %s\n", ft_strcpy(str_cpy[i], str[i]));
    if (!strcmp(str_cpy[i], str[i]))
		printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
	else
		printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
    }
    return;
}

static void test_strlen_cmp(){

    char *str[10];
    char *str_cmp[10];

    str[0] = "bonjour gautier!";
    str[1] = "bonjour gautier!";
    str[2]= "";
    str[3] = "";
    str[4] = "bonjour gautier!";
    str[5]= "OK segfault"; // 0
    str[6] = "bonjour gautier!";
    
    str_cmp[0] = "bonjour gautier!";
    str_cmp[1] = "bongour gautier!";
    str_cmp[2] = "";
    str_cmp[3] = "bongour gautier!";
    str_cmp[4] = "";
    str_cmp[5] = "bongour gautier!";
    str_cmp[6] = "OK segfault"; // 0

    for(int i = 0; i < 7; i++){
        printf("Ma ft_strlen asm : %d\n", ft_strlen(str[i]));
        printf("La strlen asm : %d\n\n", strlen(str[i]));
        printf("Ma strcmp asm : %d\n", ft_strcmp(str[i], str_cmp[i]));
        printf("La strcmp libC %d\n", strcmp(str[i], str_cmp[i]));
        if (ft_strlen(str[i]) == strlen(str[i]))
            printf(COLOR_GREEN"ft_strlen OK\n"COLOR_RESET);
        else
            printf(COLOR_RED"ft_strlen FAILED\n"COLOR_RESET);
        if (ft_strcmp(str[i], str_cmp[i]) == strcmp(str[i], str_cmp[i]))
            printf(COLOR_GREEN"ft_strcmp OK\n"COLOR_RESET);
        else
            printf(COLOR_RED"ft_strcmp FAILED\n"COLOR_RESET);
        printf("\n-----------------------------\n");

    }
    return;

}

static void     test_write()
{
    char *str_w1 = "Test de write sur un mauvais fd\n";
    char *str_w2 = "Test de ft_write sur un mauvais fd\n";
    char *str_w3 = "";
    char *str_w4 = "Test de write sur un bon fd\n";
    char *str_w5 = "Test de ft_write sur un bon fd\n";

    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = 0;

    printf("%s", str_w1);
    d1= write(12, str_w1, strlen(str_w1));
    printf("\n");
    printf("%s", str_w2);
    d2 = ft_write(12, str_w2, strlen(str_w2));
    printf("\n");
    printf("Retour write : %d     Retour ft_write : %d\n", d1, d2);
    if (d1 == d2)
        printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
    printf("----------------\n");

    printf("Test write avec NULL", str_w3);
    d3 = ft_write(12, str_w3, strlen(str_w3));
    printf("\n");
    printf("Test ft_write avec NULL", str_w3);
    d4 = ft_write(12, str_w3, strlen(str_w3));
    printf("\n");
    printf("Retour write : %d     Retour ft_write : %d\n", d3, d4);
    if (d3 == d4)
        printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
    printf("----------------\n");

    printf("%s", str_w4);
    d1= write(12, str_w4, strlen(str_w4));
    printf("\n");
    printf("%s", str_w2);
    d2 = ft_write(12, str_w2, strlen(str_w2));
    printf("\n");
    printf("Retour write : %d     Retour ft_write : %d\n", d1, d2);
    if (d1 == d2)
        printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
    printf("----------------\n");

}

static void test_read(){

    char *path_1 = "./tests/test_1.txt";
    char *path_2 = "./tests/test_2.txt";
    char *path_3 = "./tests/test_3.txt";
    char *path_4 = "./tests/test_4.txt";
    char *path_5 = "";

    int fd1 = open(path_1, O_RDWR | O_CREAT);
    int fd2 = open(path_2, O_RDWR | O_CREAT);
    int fd3 = open(path_3, O_RDWR | O_CREAT);
    int fd4 = open(path_4, O_RDWR | O_CREAT);
    int fd5 = open(path_5, O_RDWR | O_CREAT);

    int fd[10];
    fd[0] = fd1;
    fd[1] = fd2;
    fd[2] = fd3;
    fd[3] = fd4;
    fd[4] = fd5;

    char buf1[100], buf2[100], buf3[100], buf4[100], buf5[100]; 
    char buf_lib1[100], buf_lib2[100], buf_lib3[100], buf_lib4[100], buf_lib5[100]; 

    char *buf[10];
    buf[0] = buf1;
    buf[1] = buf2;
    buf[2] = buf3;
    buf[3] = buf4;
    buf[4] = buf5;

    char *buf_lib[10];
    buf_lib[0] = buf_lib1;
    buf_lib[1] = buf_lib2;
    buf_lib[2] = buf_lib3;
    buf_lib[3] = buf_lib4;
    buf_lib[4] = buf_lib5;

    int ret;
    int ret_lib;

    for (int i = 0; i < 5; i++){
        ret = ft_read(fd[i], buf[i], 10);
        printf("buf : %s\n", buf[i]);
        lseek(fd[i], 0, SEEK_SET);
        ret_lib = read(fd[i], buf_lib[i], 10);
        printf("buf_lib : %s\n", buf_lib[i]);
        printf("Return of read: %d\nReturn of ft_read: %d\n", ret_lib, ret);
        if (ret == ret_lib)
            printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
        else
            printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
        printf("----------------\n");
    }

    // Errors
    printf("Test on bad fd: \n");
    ret = ft_read(12, buf4, 100);
    ret_lib = read(12, buf4, 100);
    printf("Return of read: %d\nReturn of ft_read: %d\n", ret_lib, ret);
    if (ret == ret_lib)
        printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
    printf("----------------\n");

    printf("Test on NULL buffer: \n");
    ret = ft_read(12, 0, 100);
    ret_lib = read(12, 0, 100);
    printf("Return of read: %d\nReturn of ft_read: %d\n", ret_lib, ret);
        if (ret == ret_lib)
            printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
        else
            printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
        printf("----------------\n");

}

static void    test_strdup(){

    char *dup[12];
    dup[0] = "C'est joli!\n";
    dup[1] = "Hello moi c gvann, ca gaz?";
    dup[2] = "On va tenter un truc bien bien plus long et bien relou Wesh\n";
    dup[3] = "";
    // dup[4] = 0;

    for (int i = 0; i < 4; i++){
        printf("Ceci est un retour de ma fonction ft_strdup : %s\n", ft_strdup(dup[i]));
        printf("Ceci est l retour de strdup : %s\n", strdup(dup[i]));
        if (!strcmp(ft_strdup(dup[i]), strdup(dup[i])))
            printf(COLOR_GREEN"OK\n\n"COLOR_RESET);
        else
            printf(COLOR_RED"FAILED\n\n"COLOR_RESET);
        printf("----------------\n");
    }

}

int     main(void)
{
    // char *str = "Hello World!";
    // printf("len de '%s' : %d\n\n", str, ft_strlen(str));


    printf("\nTEST STRCPY ------------------------------\n\n");
    test_strcpy();
    printf("\nTEST STRLEN ------------------------------\n\n");
    test_strlen_cmp();
    printf("\nTEST WRITE ------------------------------\n\n");
    test_write();
    printf("\nTEST READ ------------------------------\n\n");
    test_read();
    printf("\nTEST STRDUP ------------------------------\n\n");
    test_strdup();

    return (0);
}
