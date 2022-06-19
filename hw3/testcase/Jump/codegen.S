// enter funciton body
.global codegen
codegen:
addi sp, sp, -200
sd ra, 192(sp)
sd fp, 184(sp)
addi fp, sp, 200

// array declaration
li t0, -48
sd t0, -40(fp)
// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 1000
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
sd t1, 0(t0)

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
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
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
sd t1, 0(t0)

// push num to stack
li t0, 3
addi sp, sp, -8
sd t0, 0(sp)

// push the address of array's element to the stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 3000
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
sd t1, 0(t0)

// push num to stack
li t0, 4
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// address
ld t0, 0(sp)
addi sp, sp, 8
sd t0, -88(fp)

// push value of pointer to stack
li t1, 88
sub t1, fp, t1
ld t0, 0(t1)
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 4000
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
sd t1, 0(t0)

// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// push num to stack
li t0, 3
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// push num to stack
li t0, 4
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -96(fp)

// push ident offset to stack
li t0, 96
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push the address of array's element to the stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 2500
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
sd t1, 0(t0)

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
li t3, 8
mul t1, t1, t3
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// exit function body
ld ra, 192(sp)
ld fp, 184(sp)
addi sp, sp, 200
jr ra
