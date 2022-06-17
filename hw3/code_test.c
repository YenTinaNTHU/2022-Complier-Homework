#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"

int main(){
    init_execute_func();
    push_execute_func("a");
    print_execute_func();
    push_execute_func("test");
    print_execute_func();
    push_execute_func("foo");
    print_execute_func();
    pop_execute_func();
    print_execute_func();
    pop_execute_func();
    print_execute_func();
    pop_execute_func();
    print_execute_func();
    return 0;
}