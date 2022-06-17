make
dir=testcase/ArithmeticExpression
file=$dir/1.c
./parser < ./$file > ./ans.txt

cp codegen.S ./$dir/codegen.S
cd ./$dir/

riscv64-unknown-elf-gcc -o expr main.c codegen.S
spike pk expr

cd ../..
make clean