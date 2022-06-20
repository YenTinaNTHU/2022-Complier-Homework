make
dir=testcase/Bonus
file=0.c
./parser < ./$dir/$file > ./ans.txt

cp codegen.S ./$dir/codegen.S
cd ./$dir/

riscv64-unknown-elf-as-rvp -march=rv64g_zpn -o codegen.o codegen.S

riscv64-unknown-elf-gcc -o bonus main.c codegen.o
spike pk bonus

cd ../..
make clean