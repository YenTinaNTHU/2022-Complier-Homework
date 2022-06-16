#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "code.h"

void init_symbol_table(){
    bzero(&table[0], sizeof(struct symbol_entry)*MAX_TABLE_SIZE);
}
