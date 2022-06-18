#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE_SIZE 5000
#define MAX_ARGUMENT_NUM 3
#define MAX_LOCAL_NUM 3
#define FRAME_SIZE (2 + MAX_ARGUMENT_NUM + MAX_LOCAL_NUM) * 8

#define T_FUNCTION 1
#define T_POINTER 2
#define T_CHAR 3
#define T_INT 4
#define T_FLOAT 5

#define ARGUMENT_MODE 6
#define LOCAL_MODE 7
#define GLOBAL_MODE 8

void init_symbol_table();
int install_symbol(char *name);
int look_up_symbol(char *name);
void pop_up_symbol(int scope);
void print_symbol_table(int n);

void set_local_vars(char *name);
void set_global_vars(char *name);
void set_int_type(char *name);
void set_ptr_type(char *name);
void set_scope_and_offset_of_param(char *functor);

void init_execute_func();
void push_execute_func(char*func_name);
void pop_execute_func();
void print_execute_func();

typedef struct symbol_entry *PTR_SYMB;

struct symbol_entry {
   char *name;
   int scope;
   int mode;

   int offset;
   int type;
   int total_args;
   int total_locals;
   
} table[MAX_TABLE_SIZE];

char* exe_func[MAX_TABLE_SIZE];
int exe_func_counter;

extern int cur_scope;
extern int cur_counter; // number of symbol in the table
FILE* codegen;