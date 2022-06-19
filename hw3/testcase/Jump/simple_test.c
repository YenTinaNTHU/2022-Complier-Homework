void codegen();
void codegen() {
  int input_data[17];
  int i;
  for (i = 0; i < 17; i = i + 1) {
    input_data[i] = i;
    delay(input_data[i]);
  }
  int end = 0;
  int data[17];
  for (i = 0; i < 17; i = i + 1) {
    int *id = input_data + i * 8;
  }
}