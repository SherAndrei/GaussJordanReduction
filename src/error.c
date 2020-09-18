#include "error.h"
#include <stdio.h>

static int error_code = 0;

int print_input_error(const char* error_name, int error_number) {                 
    printf("Wrong input %s: %d\n", error_name, error_number);
    return --error_code;
}

int print_function_error(const char* error_func_name) {                 
    printf("Error during %s\n", error_func_name);
    return --error_code;
}
