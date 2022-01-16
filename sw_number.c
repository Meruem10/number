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
    for(uint8_t i = 0; i < 2*SMALL_NUMBER_BITS - 1; i++)
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

    // print_bit_array(num_struct.high, SMALL_NUMBER_BITS);
    // print_bit_array(num_struct.low, SMALL_NUMBER_BITS);

    // Decimal number into binary and then into struct
    for(char i = 2*SMALL_NUMBER_BITS - 1; i >= 0; i--)
    {
        if(i >= SMALL_NUMBER_BITS)  // higher bits
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
        else                        // lower bits
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
large_number all_operation(large_number* num_1, large_number* num_2, int choice); // can re-use the code for all mathematical operations

/*
large_number add(large_number* num_1, large_number* num_2)
{
    // Array saving small_number_type as unisigned chars (i.e. index each byte)
    uint8_t num_1_low_bytes[SMALL_NUMBER_BYTES];
    uint8_t num_1_high_bytes[SMALL_NUMBER_BYTES];
    memset(num_1_low_bytes, 0, SMALL_NUMBER_BYTES);
    memset(num_1_high_bytes, 0, SMALL_NUMBER_BYTES);
    
    uint8_t num_2_low_bytes[SMALL_NUMBER_BYTES];
    uint8_t num_2_high_bytes[SMALL_NUMBER_BYTES];
    memset(num_2_low_bytes, 0, SMALL_NUMBER_BYTES);
    memset(num_2_high_bytes, 0, SMALL_NUMBER_BYTES);

    uint8_t num_3_low_bits[SMALL_NUMBER_BITS];
    uint8_t num_3_high_bits[SMALL_NUMBER_BITS];
    memset(num_3_low_bits, 0, SMALL_NUMBER_BITS);
    memset(num_3_high_bits, 0, SMALL_NUMBER_BITS);

    // Copy 
    memcpy(num_1_low_bytes, &num_1->low, sizeof(small_number_type));
    memcpy(num_1_high_bytes, &num_1->high, sizeof(small_number_type));
    memcpy(num_2_low_bytes, &num_2->low, sizeof(small_number_type));
    memcpy(num_2_high_bytes, &num_2->high, sizeof(small_number_type));

    // Go through all Bits of lower half
    uint8_t num_1_low_bit = 0;
    uint8_t num_2_low_bit = 0;
    uint8_t num_1_high_bit = 0;
    uint8_t num_2_high_bit = 0;

    uint8_t carry = 0;
    for(uint8_t i = 0; i < SMALL_NUMBER_BITS; i++)
    {
        // Link: https://stackoverflow.com/questions/44978126/structure-for-an-array-of-bits-in-c
        // First part gives me the value in the specific Byte
        // Second part shifts a 1 to the specific Bit location and compares with the Byte to see if it is a 1
        num_1_low_bit = ((num_1_low_bytes[i/8]) & (1 << (i%8))) != 0; 
        num_2_low_bit = ((num_2_low_bytes[i/8]) & (1 << (i%8))) != 0;

        // Addition
        switch(num_1_low_bit + num_2_low_bit + carry)
        {
            case 0:
                num_3_low_bits[i] = 0;
                carry = 0;
                break;
            case 1:
                num_3_low_bits[i] = 1;
                carry = 1;
                break;
            case 2:
                num_3_low_bits[i] = 0;
                carry = 1;
                break;
            case 3:
                num_3_low_bits[i] = 1;
                carry = 1;
                break;
        }
    }

    // Go through all Bits of higher half
    for(uint8_t i = 0; i < SMALL_NUMBER_BITS; i++)
    {
        num_1_high_bit = ((num_1_high_bytes[i/8]) & (1 << (i%8))) != 0; // Link: https://stackoverflow.com/questions/44978126/structure-for-an-array-of-bits-in-c
        num_2_high_bit = ((num_2_high_bytes[i/8]) & (1 << (i%8))) != 0; 

        // Addition
        switch(num_1_high_bit + num_2_high_bit + carry)
        {
            case 0:
                num_3_high_bits[i] = 0;
                carry = 0;
                break;
            case 1:
                num_3_high_bits[i] = 1;
                carry = 1;
                break;
            case 2:
                num_3_high_bits[i] = 0;
                carry = 1;
                break;
            case 3:
                num_3_high_bits[i] = 1;
                carry = 1;
                break;
        }
    }
    
    // Check for overflow
    if(carry == 1)
    {
        printf("Overflow happens!");
    }

    // Convert Bit array to decimal number and return large_number struct
    large_number num_3 = {.high = 0, .low = 0};
    for(uint8_t i = 0; i < SMALL_NUMBER_BITS; i++)
    {
        // Bit*2^i
        num_3.low += (1 << i)*num_3_low_bits[i]; 
        num_3.high += (1 << i)*num_3_high_bits[i];
    }

    return num_3;
}
*/

large_number subtract(large_number* num_1, large_number* num_2)
{

}

large_number multiply(large_number* num_1, large_number* num_2)
{

}

large_number division(large_number* num_1, large_number* num_2)
{

}
