#include<stdio.h>
#include<stdlib.h>
#include "sw_number.h"

int main(void)
{   
    // Some prints
    printf("Maximum small number: %u\n", SMALL_NUMBER_MAX_VALUE);
    printf("Maximum large number: %u\n", LARGE_NUMBER_MAX_VALUE);

    // Some test cases
    unsigned int num_1 = 65530;
    large_number num_1_struct = num_to_struct(num_1);

    unsigned int num_2 = 7;
    large_number num_2_struct = num_to_struct(num_2);

    large_number num_3_struct = add(&num_1_struct, &num_2_struct);

    printf("\nNumber 1: \n");
    print_num_binary(&num_1_struct);
    print_num_decimal(&num_1_struct);
    printf("\n");

    printf("Number 2: \n");
    print_num_binary(&num_2_struct);
    print_num_decimal(&num_2_struct);
    printf("\n");

    printf("Number 1 + Number 2: \n");
    print_num_binary(&num_3_struct);
    print_num_decimal(&num_3_struct);
    printf("\n");


    return 0;
}
