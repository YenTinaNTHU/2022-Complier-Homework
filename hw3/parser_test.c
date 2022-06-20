  void codegen();
  int func1(int a, int b);
  int func2(int a, int b);

  void codegen() {
    int tmp1;
    int a = func1(1,2);
    delay(a);
    int b = func2(3,4);
    delay(b);
  }

  int func1(int a, int b){
    int tmp2 = a + b;
    return tmp2;
  }
   int func2(int a, int b){
    int tmp3 = a - b;
    return tmp3;
  }



