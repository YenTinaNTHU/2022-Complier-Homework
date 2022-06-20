void codegen();
int func1(const int *a, const int *b);

void codegen() {
  const int tmp1 = 1;
  const int tmp2 = 2;
  delay(tmp2);delay(&tmp2);
  int a = func1(&tmp1,&tmp2);
  delay(a); // a = 3
}

int func1(const int *a, const int *b){
  int tmp2 = *a + *b;
  return tmp2;
}