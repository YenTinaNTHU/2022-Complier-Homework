void codegen();
int getNum(int a, int b);

void codegen() {
  int a = getNum(1,2);
  delay(a);
}

int getNum(int a, int b){
  return a + b;
}