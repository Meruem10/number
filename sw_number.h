#ifndef SW_NUMBER_H
#define SW_NUMBER_H

// Typedefs
typedef unsigned char uint8_t;
typedef uint8_t small_number_type; // set the small number type (assuming unsigned variant)

// Macros
#define SMALL_NUMBER_MAX_VALUE (1 << sizeof(small_number_type)*8) - 1 // maximum value of smaller datatype
#define LARGE_NUMBER_MAX_VALUE (1 << 2*sizeof(small_number_type)*8) - 1 // maximum value of larger datatype

#define SMALL_NUMBER_BITS sizeof(small_number_type)*8
#define LARGE_NUMBER_BITS 2*SMALL_NUMBER_BITS

#define SMALL_NUMBER_BYTES sizeof(small_number_type)
#define LARGE_NUMBER_BYTES 2*SMALL_NUMBER_BYTES

// Struct
typedef struct  {
    uint8_t high[SMALL_NUMBER_BITS]; // higer bits
    uint8_t low[SMALL_NUMBER_BITS]; // lower bits
} large_number;


// Function declaration (i.e. prototypes)
large_number add(large_number* num_1, large_number* num_2);
large_number subtract(large_number* num_1, large_number* num_2);
large_number multiply(large_number* num_1, large_number* num_2);
large_number division(large_number* num_1, large_number* num_2);

// Helper
void print_num_binary(large_number* num);
void print_num_decimal(large_number* num);
large_number num_to_struct(unsigned int num);

#endif