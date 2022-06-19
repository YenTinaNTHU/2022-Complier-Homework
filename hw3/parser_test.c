void codegen();

void codegen() {
  int a[5];
  // a[1] = 1000;
  // a[2] = a[1] + 1000;
  // *(a + 3) = 3000;
  // delay(a[1]);
  // delay(a[2]);
  // delay(a[3]);

  int *b = &a[4];
  delay(b);
  *b = 4000;
  delay(a[4]);
}
