void codegen();
void codegen() {
  int i = 0;
  int b = 0;
  for(i = 0; i < 2; i = i + 1){
    b = b + 1;
    delay(b);
  }
  
  for(i = 0; i < 2; i = i + 1){
    b = b + 1;
    delay(b);
  }
}