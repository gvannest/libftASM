
#include <stdio.h>


#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}              t_list;


int			ft_atoi_base(char *nb, char *base);
void        ft_list_push_front(t_list **begin_list, void *data);
int         ft_list_size(t_list *begin_list);
void        ft_list_sort(t_list **begin_list, int (*cmp)());
int		    ft_strcmp(const char *s1, char *s2);
void        ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

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

static  void    test_push_front_size(){
    t_list        **begin;

    t_list        node_lists[5];

    char        *data1 = "Salut ca va?";
    int         data2 = 3;
    char        data3 = 'a';

    node_lists[0].data = (void*)data1;
    node_lists[1].data = (void*)(&data2);
    node_lists[2].data = (void*)(&data3);

    node_lists[0].next = &(node_lists[1]);
    node_lists[1].next = &(node_lists[2]);
    node_lists[2].next = NULL;

    *begin = &(node_lists[0]);

    char    *test_data = "ca marche!! Youhou!";

    ft_list_push_front(begin, (void*)test_data);

    t_list      *list = *begin;
    int i =0;
    while (list != NULL){
        printf("structure at index %d :\n", i);
        if (i != 2){
            printf("\tdata: %s\n", (char*)(list->data));
            printf("\tpointer: %p\n", list);
        }
        else{
            printf("\tdata: %d\n", *((int*)(list->data)));
            printf("\tpointer: %p\n", list);
        }
        i++;
        list = list->next;
    }

    list = *begin;
    i = ft_list_size(list);
    printf("\nList size is : %d\n", i);
}

int     comp_int(int *a, int *b)
{
    return (*a - *b);
}

static void     test_sort(){
    t_list        *begin;

    t_list        node_lists[12];

    char *        data1 = "abcd";
    char *        data2 = "abbz";
    char *        data3 = "";
    char *        data4 = "abcdefgh";
    char *        data5 = "abcdefgh";
    char *        data6 = "abcdefz";

    node_lists[0].data = (void*)(data1);
    node_lists[1].data = (void*)(data2);
    node_lists[2].data = (void*)(data3);
    node_lists[3].data = (void*)(data4);
    node_lists[4].data = (void*)(data5);
    node_lists[5].data = (void*)(data6);

    node_lists[0].next = &(node_lists[1]);
    node_lists[1].next = &(node_lists[2]);
    node_lists[2].next = &(node_lists[3]);
    node_lists[3].next = &(node_lists[4]);
    node_lists[4].next = &(node_lists[5]);
    node_lists[5].next = NULL;


    begin = node_lists;

    ft_list_sort(&begin, &ft_strcmp);

    t_list      *list = begin;
    int i =0;
    while (list != NULL){
        printf("structure at index %d :\n", i);
            printf("\tdata: %s\n", ((char*)(list->data)));
        i++;
        list = list->next;
    }  

    char *delete = "aaaaq";
    printf("\n----------------\nNow delete data : %s\n\n", delete);
    ft_list_remove_if(&begin, (void*)(delete), NULL);

    list = begin;
    i =0;
    while (list != NULL){
        printf("structure at index %d :\n", i);
            printf("\tdata: %s\n", ((char*)(list->data)));
        i++;
        list = list->next;
    }  

    printf("\n\n----------------\n\nAvec des int: \n\n");
        int        data10 = 8;
    int        data20 = 3;
    int        data30 = 5;
    int        data40 = -2;
    int        data50 = 5;
    int        data60 = 0;

    node_lists[0].data = (void*)(&data10);
    node_lists[1].data = (void*)(&data20);
    node_lists[2].data = (void*)(&data30);
    node_lists[3].data = (void*)(&data40);
    node_lists[4].data = (void*)(&data50);
    node_lists[5].data = (void*)(&data60);

    node_lists[0].next = &(node_lists[1]);
    node_lists[1].next = &(node_lists[2]);
    node_lists[2].next = &(node_lists[3]);
    node_lists[3].next = &(node_lists[4]);
    node_lists[4].next = &(node_lists[5]);
    node_lists[5].next = NULL;


    begin = node_lists;

    ft_list_sort(&begin, &comp_int);

    list = begin;
    i =0;
    while (list != NULL){
        printf("structure at index %d :\n", i);
            printf("\tdata: %d\n", *((int*)(list->data)));
        i++;
        list = list->next;
    }  

    int del = 5;
    printf("\n----------------\nNow delete data : %d\n\n", del);
    ft_list_remove_if(&begin, (void*)(&del), &comp_int);

    list = begin;
    i =0;
    while (list != NULL){
        printf("structure at index %d :\n", i);
            printf("\tdata: %d\n", *((int*)(list->data)));
        i++;
        list = list->next;
    }  

    
}

int     main(){
    // test_atoi();
    test_push_front_size();
    // test_sort();
    return 0;
}