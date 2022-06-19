void codegen();

void codegen() {
  int a[5];
  a[1] = 1000;
  a[2] = a[1] + 1000;
  *(a + 3) = 3000;
  int *b = &a[4];
  *b = 4000;
  delay(a[1]);
  delay(a[2]);
  delay(a[3]);
  delay(a[4]);

  int c = 2;
  *(a + c) = 2500;
  delay(a[2]);
}
