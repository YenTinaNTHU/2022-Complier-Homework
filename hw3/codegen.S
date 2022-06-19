// enter funciton body
.global codegen
codegen:
addi sp, sp, -240
sd ra, 232(sp)
sd fp, 224(sp)
addi fp, sp, 240

// array declaration
li t0, 48
sd t0, -40(fp)
// push ident offset to stack
li t0, 184
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
sub t0, fp, t0
sd t1, 0(t0)

.FOR1:
// push ident offset to stack
li t0, 184
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
li t0, 17
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
// push ident offset to stack
li t0, 184
addi sp, sp, -8
sd t0, 0(sp)

// push ident offset to stack
li t0, 184
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
sub t0, fp, t0
sd t1, 0(t0)

j .FOR1
.FOR_STMT1:
// push ident offset to stack
li t0, 184
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

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

// push ident offset to stack
li t0, 184
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
sd t1, 0(t0)

// push ident offset to stack
li t0, 184
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

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

j .FOR_UPDATE1

.END_FOR1:
// push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -192(fp)

// array declaration
li t0, 208
sd t0, -200(fp)
// push ident offset to stack
li t0, 184
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
sub t0, fp, t0
sd t1, 0(t0)

.FOR2:
// push ident offset to stack
li t0, 184
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
li t0, 17
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
beq zero, t0, .END_FOR2
j .FOR_STMT2
.FOR_UPDATE2:
// push ident offset to stack
li t0, 184
addi sp, sp, -8
sd t0, 0(sp)

// push ident offset to stack
li t0, 184
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
sub t0, fp, t0
sd t1, 0(t0)

j .FOR2
.FOR_STMT2:
// push ident offset to stack
li t0, 40
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push ident offset to stack
li t0, 184
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)


ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -344(fp)

j .FOR_UPDATE2

.END_FOR2:
// exit function body
ld ra, 232(sp)
ld fp, 224(sp)
addi sp, sp, 240
jr ra
