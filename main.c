#include<stdio.h>
#include "sw_number.h"

int main(void)
{   
    // Some prints
    printf("Maximum small number: %u\n", SMALL_NUMBER_MAX_VALUE);
    printf("Maximum large number: %u\n", LARGE_NUMBER_MAX_VALUE);

    // Some test cases
    unsigned int num = 300;
    large_number num_struct = num_to_struct(300);
    print_num_binary(&num_struct);
    print_num_decimal(&num_struct);


    return 0;
}
