make
dir=testcase/Jump
file=simple_test.c
./parser < ./$dir/$file > ./ans.txt

cp codegen.S ./$dir/codegen.S
cd ./$dir/

riscv64-unknown-elf-gcc -o expr main.c codegen.S
spike pk expr

cd ../..
make clean