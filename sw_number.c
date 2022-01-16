#include<stdio.h>
#include "sw_number.h"

void * memcpy ( void * destination, const void * source, long unsigned int num); // function from string.h library


void print_num(large_number* num)
{
    small_number_type high_digit = num->high;
    small_number_type low_digit = num->low;

    printf("Number is: %u%u\n", high_digit, low_digit);
}

large_number add(large_number* num_1, large_number* num_2)
{
    // Array saving small numbers as unisigned chars
    uint8_t num_1_low_bits[SMALL_NUMBER_BITS];
    uint8_t num_1_high_bits[SMALL_NUMBER_BITS];
    
    uint8_t num_2_low_bits[SMALL_NUMBER_BITS];
    uint8_t num_2_high_bits[SMALL_NUMBER_BITS];

    // Copy 
    memcpy(num_1_low_bits, &num_1->low, sizeof(small_number_type));
    memcpy(num_1_high_bits, &num_1->high, sizeof(small_number_type));
    memcpy(num_2_low_bits, &num_2->low, sizeof(small_number_type));
    memcpy(num_2_high_bits, &num_2->high, sizeof(small_number_type));



    

}

large_number subtract(large_number* num_1, large_number* num_2)
{

}

large_number multiply(large_number* num_1, large_number* num_2)
{

}

large_number division(large_number* num_1, large_number* num_2)
{

}
