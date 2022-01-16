#include<stdio.h> // printf() function
#include<stdlib.h> // exit(0) function
#include "sw_number.h"

void * memcpy ( void * destination, const void * source, long unsigned int num); // function from <string.h> library
void * memset(void *str, int c, long unsigned int n);


// Helper
void print_bit_array(uint8_t* bit_array, uint8_t size)
{
    for(char i = size-1; i >= 0; i--)
    {
        printf("%d", bit_array[i]);
    }
}

void print_num_binary(large_number* num)
{
    small_number_type* low = num->low; // uint8_t array of bits
    small_number_type* high = num->high;

    printf("Binary number: ");
    print_bit_array(high, SMALL_NUMBER_BITS); 
    print_bit_array(low, SMALL_NUMBER_BITS);
    printf("\n");
}

void print_num_decimal(large_number* num)
{
    unsigned int dec_num = 0;
    for(uint8_t i = 0; i < 2*SMALL_NUMBER_BITS; i++)
    {
        if(i < SMALL_NUMBER_BITS)               // lower bits
        {
            dec_num += (1 << i)*num->low[i];
        }
        else                                    // higher bits
        {
            dec_num += (1 << i)*num->high[i - SMALL_NUMBER_BITS];
        }
    }

    printf("Decimal number: %u\n", dec_num);
}

// Number to struct
large_number num_to_struct(unsigned int num)
{
    if(num > LARGE_NUMBER_MAX_VALUE)
    {
        printf("The number is too large and cannot be represented using two of smaller datatype\n");
        exit(0);
    }
    
    // Initialization
    large_number num_struct;
    memset(&num_struct.high, 0, SMALL_NUMBER_BITS);
    memset(&num_struct.low, 0, SMALL_NUMBER_BITS);

    // Decimal number into binary and then into struct
    for(char i = 2*SMALL_NUMBER_BITS - 1; i >= 0; i--)
    {
        if(i >= SMALL_NUMBER_BITS)                                              // higher bits
        {
            if((num / (1 << i) > 0) || ((num % (1 << i) == 0) && num > 0))
            {
                num_struct.high[i - SMALL_NUMBER_BITS] = 1;
                num -= (1 << i);
            }
            else
            {
                num_struct.high[i - SMALL_NUMBER_BITS] = 0;
            }

        }
        else                                                                    // lower bits
        {
            if((num / (1 << i) > 0) || ((num % (1 << i) == 0) && num > 0))
            {
                num_struct.low[i] = 1;
                num -= (1 << i);
            }
            else
            {
                num_struct.low[i] = 0;
            }
        }
    }
    if(num != 0)
    {
        printf("%d\n", num);
        printf("Error: Decimal is not correctly turned into binary\n");
    }
    return num_struct;
}

// Mathematical operations
large_number add(large_number* num_1, large_number* num_2)
{
    // Initialization
    large_number num_3;
    memset(&num_3.low, 0, SMALL_NUMBER_BYTES);
    memset(&num_3.high, 0, SMALL_NUMBER_BYTES);

    uint8_t carry = 0;
    for(uint8_t i = 0; i < 2*SMALL_NUMBER_BITS; i++)
    {
        if(i < SMALL_NUMBER_BITS) // lower bits
        {
            switch(num_1->low[i] + num_2->low[i] + carry)
            {
                case 0:
                num_3.low[i] = 0;
                carry = 0;
                break;
            case 1:
                num_3.low[i] = 1;
                carry = 0;
                break;
            case 2:
                num_3.low[i] = 0;
                carry = 1;
                break;
            case 3:
                num_3.low[i] = 1;
                carry = 1;
                break; 
            }
        }
        else // higher bits
        {
            switch(num_1->high[i - SMALL_NUMBER_BITS] + num_2->high[i - SMALL_NUMBER_BITS] + carry)
            {
                case 0:
                num_3.high[i -  SMALL_NUMBER_BITS] = 0;
                carry = 0;
                break;
            case 1:
                num_3.high[i - SMALL_NUMBER_BITS] = 1;
                carry = 0;
                break;
            case 2:
                num_3.high[i - SMALL_NUMBER_BITS] = 0;
                carry = 1;
                break;
            case 3:
                num_3.high[i - SMALL_NUMBER_BITS] = 1;
                carry = 1;
                break; 
            }
        }
    }

    // Overflow
    if(carry == 1)
    {
        printf("There is an overflow!\n");
    }

    return num_3;
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
