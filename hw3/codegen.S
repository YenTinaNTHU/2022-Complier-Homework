// enter funciton body
.global codegen
codegen:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456

// array declaration
li t0, -72
add t0, fp, t0
sd t0, -64(fp)
// count the address value
li t0, -112
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sd t1, 0(t0)

.FOR1:
// count the address value
li t0, -112
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 5
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
sub t2, t1, t0
slt t3, t2, zero
addi sp, sp, -8
sd t3, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
beq zero, t0, .END_FOR1
j .FOR_STMT1
.FOR_UPDATE1:
// count the address value
li t0, -112
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// count the address value
li t0, -112
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sd t1, 0(t0)

j .FOR1
.FOR_STMT1:
// count the address value
li t0, -112
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push the address of array element to the stack
ld t0, -64(fp)
ld t1, 0(sp)
addi sp, sp, 8
slli t1, t1, 3
sub t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sd t1, 0(t0)

j .FOR_UPDATE1

.END_FOR1:
// count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 6
addi sp, sp, -8
sd t0, 0(sp)

// function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, dp_fib

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
sd t0, -120(fp)

// count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 4
addi sp, sp, -8
sd t0, 0(sp)

// function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, dp_fib

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
sd t0, -128(fp)

// push num to stack
li t0, 26
addi sp, sp, -8
sd t0, 0(sp)

// call digitalWrite()
ld a0, 0(sp)
addi sp, sp, 8
li a1, 1
jal ra, digitalWrite

// count the address value
li t0, -120
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 1000
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
mul t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// call delay function
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// push num to stack
li t0, 26
addi sp, sp, -8
sd t0, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
li a1, 0
jal ra, digitalWrite

// count the address value
li t0, -128
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 1000
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
mul t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// call delay function
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// exit function body
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
// enter funciton body
.global dp_fib
dp_fib:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456
sd a0, -24(fp)
sd a1, -32(fp)

// count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
xor t2, t0, t1
sltu t3, zero, t2
xori t4, t3, 1
addi sp, sp, -8
sd t4, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
beq zero, t0, .IF10
// push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

// exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
.IF10: 
// count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
xor t2, t0, t1
sltu t3, zero, t2
xori t4, t3, 1
addi sp, sp, -8
sd t4, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
beq zero, t0, .IF20
// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

// exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
.IF20: 
// count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
sub t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -64(fp)

// count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push array ident byte offset to stack
ld t0, -24(fp)
ld t1, 0(sp)
addi sp, sp, 8
slli t1, t1, 3
sub t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
xor t2, t0, t1
sltu t3, zero, t2
xori t4, t3, 1
addi sp, sp, -8
sd t4, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
beq zero, t0, .IF30
// count the address value
li t0, -24
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
sub t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, dp_fib

addi sp, sp, -8
sd a0, 0(sp)
// count the address value
li t0, -24
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
sub t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, dp_fib

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -72(fp)

// count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push array ident byte offset to stack
ld t0, -24(fp)
ld t1, 0(sp)
addi sp, sp, 8
slli t1, t1, 3
sub t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// count the address value
li t0, -72
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sd t1, 0(t0)

// count the address value
li t0, -72
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
j .IF31

.IF30:
// count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push array ident byte offset to stack
ld t0, -24(fp)
ld t1, 0(sp)
addi sp, sp, 8
slli t1, t1, 3
sub t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
.IF31:
