#include<stdio.h>
#include "sw_number.h"

int main(void)
{   
    // Some prints
    printf("Maximum small number: %u\n", SMALL_NUMBER_MAX_VALUE);
    printf("Maximum large number: %u\n", LARGE_NUMBER_MAX_VALUE);

    // Some test cases
    small_number_type num_1_low =  00;
    small_number_type num_1_high = 100; // num_1 = 100'00

    small_number_type num_2_low = 00;
    small_number_type num_2_high = 200; // num_2 = 100'00


    large_number num_1 = {.high = num_1_high, .low = num_1_low}; 
    large_number num_2 = {.high = num_2_high, .low = num_2_low};

    
    print_num(&num_1);
    print_num(&num_2);


    return 0;
}
