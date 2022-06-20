# enter funciton body
.global codegen
codegen:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456

# push num to stack
li t0, 12
addi sp, sp, -8
sd t0, 0(sp)

# push num to stack
li t0, 18
addi sp, sp, -8
sd t0, 0(sp)

# function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, gcd

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
sd t0, -64(fp)

# push num to stack
li t0, 8
addi sp, sp, -8
sd t0, 0(sp)

# push num to stack
li t0, 9
addi sp, sp, -8
sd t0, 0(sp)

# function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, gcd

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
sd t0, -72(fp)

# push num to stack
li t0, 6
addi sp, sp, -8
sd t0, 0(sp)

# push num to stack
li t0, 4
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -80(fp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -88(fp)

# push num to stack
li t0, 26
addi sp, sp, -8
sd t0, 0(sp)

# count the address value
li t0, -88
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# address
# count the address value
li t0, -80
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# address
# function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, modulo

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

# call digitalWrite()
ld a0, 0(sp)
addi sp, sp, 8
li a1, 1
jal ra, digitalWrite

# count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# push num to stack
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

# call delay function
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

# push num to stack
li t0, 26
addi sp, sp, -8
sd t0, 0(sp)

# count the address value
li t0, -88
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# address
# count the address value
li t0, -80
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# address
# function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, modulo

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
li a1, 0
jal ra, digitalWrite

# count the address value
li t0, -72
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# push num to stack
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

# call delay function
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

# exit function body
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
# enter funciton body
.global modulo
modulo:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456
sd a0, -24(fp)
sd a1, -32(fp)

# push value of pointer to stack
ld t0, -24(fp)
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# push value of pointer to stack
ld t0, -32(fp)
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

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
beq zero, t0, .IF10
# push value of pointer to stack
ld t0, -24(fp)
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
.IF10: 
# push value of pointer to stack
ld t0, -24(fp)
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -64(fp)

WHILE:
# push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
beq zero, t0, .END_WHILE
# count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# push value of pointer to stack
ld t0, -32(fp)
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
sub t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

# assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sd t1, 0(t0)

# count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# push value of pointer to stack
ld t0, -32(fp)
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

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
beq zero, t0, .IF20
j .END_WHILE
.IF20: 
j WHILE

.END_WHILE:
# count the address value
li t0, -64
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
# function definition
# enter funciton body
.global gcd
gcd:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456
sd a0, -24(fp)
sd a1, -32(fp)

# count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
xor t2, t0, t1
sltu t3, zero, t2
addi sp, sp, -8
sd t3, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
beq zero, t0, .IF30
# count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# count the address value
li t0, -24
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# address
# count the address value
li t0, -32
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# address
# function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, modulo

addi sp, sp, -8
sd a0, 0(sp)
# function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, gcd

addi sp, sp, -8
sd a0, 0(sp)
# exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
j .IF31

.IF30:
# count the address value
li t0, -24
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

# get variable's value
ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

# exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
.IF31:
