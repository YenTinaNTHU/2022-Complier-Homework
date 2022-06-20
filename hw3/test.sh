make
dir=testcase/Jump
file=1.c
./parser < ./$dir/$file > ./ans.txt

cp codegen.S ./$dir/codegen.S
cd ./$dir/

riscv64-unknown-elf-gcc -o jump main.c codegen.S
spike pk jump

cd ../..
make clean