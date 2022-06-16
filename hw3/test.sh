make
file=testcase/Basic/0.c
./parser < ./$file > ./ans.txt

cp codegen.S ./testcase/Basic/codegen.S
cd ./testcase/Basic/

riscv64-unknown-elf-gcc -o basic main.c codegen.S
spike pk basic

cd ../..
make clean