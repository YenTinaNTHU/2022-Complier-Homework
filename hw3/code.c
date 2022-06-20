#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"

int cur_scope = 0;
int cur_counter = 0;
int exe_func_counter = 0;
int if_else_counter = 0;
int if_else_pointer = 0;
int for_counter = 0;

void print_symbol_table(int n){
    printf("name      | scope | mode  | offset| type  | total_args| total_locals\n");
    for(int i=0; i<=n; i++){
        printf("%-10s| %-6d| %-6d| %-6d| %-6d| %-10d| %-12d",
            table[i].name,
            table[i].scope,
            table[i].mode,
            table[i].offset,
            table[i].type,
            table[i].total_args,
            table[i].total_locals
        );
        if(i == cur_counter){
            printf(" <---cur_counter\n");
        }else{
            printf("\n");
        }
    }
    printf("cur_scope: %d\n",cur_scope);
    printf("cur_counter: %d\n",cur_counter);
    return;
}

void print_execute_func(){
    printf("Executing Functions:\n");
    for(int i=0; i<exe_func_counter; i++){
        printf("%d: %s\n", i, exe_func[i]);
    }
}

void init_symbol_table(){
    bzero(&table[0], sizeof(struct symbol_entry)*MAX_TABLE_SIZE);
    cur_counter = 0;
}

void init_execute_func(){
    bzero(&exe_func[0], sizeof(char*)*MAX_TABLE_SIZE);
    exe_func_counter = 0;
}
void push_execute_func(char*func_name){
    if(exe_func_counter >= MAX_TABLE_SIZE){
        printf("Executing function stack full\n");
    }else{
        exe_func[exe_func_counter] = func_name;
        exe_func_counter++;
    }
}

void pop_execute_func(){
    exe_func_counter--;
}

int install_symbol(char *s){
    if(cur_counter >= MAX_TABLE_SIZE){
        printf("Symbol Table Full\n");
    }else{
        table[cur_counter].scope = cur_scope;
        table[cur_counter].name = strdup(s);
        cur_counter++;
    }
    return (cur_counter-1);
}

int look_up_symbol(char *s){
    int i;
    if(cur_counter == 0) return(-1);
    for(i = cur_counter-1; i>=0; i--){
        if(!strcmp(s, table[i].name)){
            return i;
        }
    }
    return -1;
}

void pop_up_symbol(int scope){
    int i;
    if(cur_counter == 0){
        return;
    }
    for(i = cur_counter-1; i>=0; i--){
        if(table[i].scope < scope){
            break;
        }
    }
    if(i<0){
        cur_counter = 0;
    }else{
        cur_counter = i+1;
    }
    return;
}

void set_global_vars(char *name){
    int idx = look_up_symbol(name);
    table[idx].mode = GLOBAL_MODE;
}

void set_local_vars(char *name){
    char* functor_name = exe_func[exe_func_counter-1];
    int idx = look_up_symbol(name);
    int functor_idx = look_up_symbol(functor_name);
    int offset = ++table[functor_idx].total_locals;
    table[idx].mode = LOCAL_MODE;
    table[idx].offset = offset;
}

void set_int_type(char *name){
    int idx = look_up_symbol(name);
    table[idx].type = T_INT;
}

void set_ptr_type(char *name){
    int idx = look_up_symbol(name);
    table[idx].type = T_POINTER;
}

void set_scope_and_offset_of_param(char *functor, int total_args){
    int idx = look_up_symbol(functor);
    if(idx<0){
        printf("Error in function header\n");
    }else{
        table[idx].type = T_FUNCTION;
        table[idx].total_args = total_args;
        int j = total_args;
        for(int i = cur_counter-1; j > 0; i--){
            table[i].scope = cur_scope;
            table[i].offset = j;
            table[i].mode = ARGUMENT_MODE;
            j--;
        }
    }
}

void init_if_else_stack(){
    if_else_counter = 0;
    if_else_pointer = 0;
    bzero(&if_else_stack[0], sizeof(int)*MAX_TABLE_SIZE);
}

void push_if_else_stack(int num){
    if(if_else_pointer >= MAX_TABLE_SIZE){
        printf("if-else stack full\n");
    }else{
        if_else_stack[if_else_pointer] = num;
        if_else_pointer++;
    }
}

int pop_if_else_stack(){
    int val = if_else_stack[if_else_pointer];
    if_else_pointer--;
    return val;
}