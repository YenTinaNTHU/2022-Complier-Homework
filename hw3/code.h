#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE_SIZE 5000

void init_symbol_table();
char *install_symbol(char *s);
int look_up_symbol(char *s);
void pop_up_symbol(int scope);
// void set_scope_and_offset_of_param(char *s);
// void set_local_vars(char *functor);
// void set_global_vars(char *s);
char* copys(char *s);

typedef struct symbol_entry *PTR_SYMB;

struct symbol_entry {
   char *name;
   int scope;
   int offset;
   int id;
   int variant;
   int type;
   int total_args;
   int total_locals;
   int mode;
}  table[MAX_TABLE_SIZE];

extern int cur_scope;
extern int cur_counter;
FILE* codegen;