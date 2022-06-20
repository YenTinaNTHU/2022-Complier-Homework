make
dir=testcase/Function
file=0.c
./parser < ./$dir/$file > ./ans.txt

cp codegen.S ./$dir/codegen.S
cd ./$dir/

riscv64-unknown-elf-gcc -o func main.c codegen.S
spike pk func

cd ../..
make clean