void codegen();
void codegen() {
  int a = 3;
  if(a){ // 1
    a = 1;
    if(a){ // 2
      a = 2;
      if(a){ // 3
        a = 3;
      }
      a = 2;
    }
    a = 1;
  }
}