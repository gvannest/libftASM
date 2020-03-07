
#include <stdio.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

int			ft_atoi_base(char *nb, char *base);

static void test_atoi(){

    char    *nb1 = "     \n-36A5Dt78";
    char    *base1 = "0123456789ABCDEF";
    int a = ft_atoi_base(nb1, base1);
    printf("Nombre : %s\n", nb1);
    printf("Base : %s\n", base1);
    printf("Retour atoi_base : %d\n", a);
    printf("Retour attendu : %d\n", -223837);
    if (a == -223837)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");

    char    *nb2 = "     \n-3657A5Dt78";
    char    *base2 = "0123456789";
    int b = ft_atoi_base(nb2, base2);
    printf("Nombre : %s\n", nb2);
    printf("Base : %s\n", base2);
    printf("Retour atoi_base : %d\n", b);
    printf("Retour attendu : %d\n", -3657);
    if (b == -3657)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");


    char    *nb3 = "    3B507A5Dt78";
    char    *base3 = "0123456789AB";
    int c = ft_atoi_base(nb3, base3);
    printf("Nombre : %s\n", nb3);
    printf("Base : %s\n", base3);
    printf("Retour atoi_base : %d\n", c);
    printf("Retour attendu : %d\n", 11799917);
    if (c == 11799917)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");
    
    char    *nb4 = "    +3B507A5Dt78";
    char    *base4 = "01234";
    int d = ft_atoi_base(nb4, base4);
    printf("Nombre : %s\n", nb4);
    printf("Base : %s\n", base4);
    printf("Retour atoi_base : %d\n", d);
    printf("Retour attendu : %d\n", 3);
    if (d == 3)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");

    char    *nb5 = "    395C-07A5Dt78";
    char    *base5 = "0123456789ABCDE";
    int e = ft_atoi_base(nb5, base5);
    printf("Nombre : %s\n", nb5);
    printf("Base : %s\n", base5);
    printf("Retour atoi_base : %d\n", e);
    printf("Retour attendu : %d\n", 12237);
    if (e == 12237)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");

    char    *nb8 = "    +0110101465gh";
    char    *base8 = "01";
    int h = ft_atoi_base(nb8, base8);
    printf("Nombre : %s\n", nb8);
    printf("Base : %s\n", base8);
    printf("Retour atoi_base : %d\n", h);
    printf("Retour attendu : %d\n", 53);
    if (h == 53)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");

//errors
    char    *nb6 = "    395C07A5Dt78";
    char    *base6 = "";
    int f = ft_atoi_base(nb6, base6);
    printf("Nombre : %s\n", nb6);
    printf("Base : %s\n", base6);
    printf("Retour atoi_base : %d\n", f);
    printf("Retour attendu : %d\n", 0);
    if (f == 0)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");

    char    *nb7 = "";
    char    *base7 = "01234";
    int g = ft_atoi_base(nb7, base7);
    printf("Nombre : %s\n", nb7);
    printf("Base : %s\n", base7);
    printf("Retour atoi_base : %d\n", g);
    printf("Retour attendu : %d\n", 0);
    if (g == 0)
        printf(COLOR_GREEN"OK\n"COLOR_RESET);
    else
        printf(COLOR_RED"FAILED\n"COLOR_RESET);
    
    printf("\n--------------------------\n\n");

}

int     main(){
    test_atoi();
    return 0;
}