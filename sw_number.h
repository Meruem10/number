#ifndef SW_NUMBER_H
#define SW_NUMBER_H

// Typedefs
typedef unsigned char uint8_t;
typedef uint8_t small_number_type; // set the small number type

// Macros
#define SMALL_NUMBER_MAX_VALUE = (1 << sizeof(small_number_type)*8) - 1 // maximum value of smaller datatype
#define LARGE_NUMBER_MAX_VALUE = 2*(SMALL_NUMBER_MAX_VALUE + 1) - 1 // maximum value of larger datatype

// Struct
typedef struct  {
    small_number_type high; // higer bits
    small_number_type low; // lower bits
} large_number;


// Function declaration (i.e. prototypes)
large_number add(large_number* num_1, large_number* num_2);
large_number subtract(large_number* num_1, large_number* num_2);
large_number multiply(large_number* num_1, large_number* num_2);
large_number division(large_number* num_1, large_number* num_2);


#endif