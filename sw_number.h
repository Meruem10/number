#ifndef SW_NUMBER_H
#define SW_NUMBER_H


// Typedefs
typedef unsigned char uint8_t;
typedef uint8_t small_number_type; // set the small number type

// Struct
typedef struct  {
    small_number_type high; // higer bits
    small_number_type low; // lower bits
} large_number;


// Functions
large_number add(small_number_type* num_1_high, small_number_type* num_1_low, small_number_type* num_2_high, small_number_type* num_2_low);

large_number subtract(small_number_type* num_1_high, small_number_type* num_1_low, small_number_type* num_2_high, small_number_type* num_2_low);

large_number multiply(small_number_type* num_1_high, small_number_type* num_1_low, small_number_type* num_2_high, small_number_type* num_2_low);

large_number division(small_number_type* num_1_high, small_number_type* num_1_low, small_number_type* num_2_high, small_number_type* num_2_low);

#endif