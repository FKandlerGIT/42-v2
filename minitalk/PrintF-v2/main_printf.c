#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int main(void)
{
    int std_ret;
    int my_ret;

    printf("Standard printf results:\n");
    std_ret = printf(" |std| %d | %d | %d | %i | %i | %i |\n |%p", 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN);
    printf("Return value from std printf: %d\n\n", std_ret);

    printf("Your ft_printf results:\n");
    my_ret = ft_printf(" |ft_| %d | %d | %d | %i | %i | %i |\n", 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN);
    printf("Return value from ft_printf: %d\n", my_ret);

    return 0;
}
//make       
//gcc main.c -L. -lftprintf -o test_printf