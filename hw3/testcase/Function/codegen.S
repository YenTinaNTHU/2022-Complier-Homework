// enter funciton body
.global codegen
codegen:
addi sp, sp, -440
sd ra, 432(sp)
sd fp, 424(sp)
addi fp, sp, 440

// array declaration
li t0, 6
sd t0, -40(fp)
// push num to stack
li t0, 0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -104(fp)

DOWHILE:
// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
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
// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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
add t0, t0, t1
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
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
sd t1, 0(t0)

j .IF11

.IF10:
// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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
xor t2, t0, t1
sltu t3, zero, t2
xori t4, t3, 1
addi sp, sp, -8
sd t4, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
beq zero, t0, .IF20
// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
sd t1, 0(t0)

j .IF21

.IF20:
// push ident offset to stack
li t0, 5
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -112(fp)

// push ident offset to stack
li t0, 5
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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
sd t0, -120(fp)

// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// push value of pointer to stack
li t1, 112
sub t1, fp, t1
ld t0, 0(t1)
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push value of pointer to stack
li t1, 120
sub t1, fp, t1
ld t0, 0(t1)
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
sd t1, 0(t0)

.IF21:
.IF11:
// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
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
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
sd t1, 0(t0)

// push ident offset to stack
li t0, 13
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

// push num to stack
li t0, 7
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
beq zero, t0, END_DOWHILE
j DOWHILE

END_DOWHILE:
li a0, 28
li a1, 1
jal ra, digitalWrite

// push num to stack
li t0, 6
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

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
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
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

ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

li a0, 28
li a1, 0
jal ra, digitalWrite

// push num to stack
li t0, 5
addi sp, sp, -8
sd t0, 0(sp)

// push array's ident byte offset to stack
li t1, 40
sub t1, fp, t1
ld t0, 0(t1)
ld t1, 0(sp)
addi sp, sp, 8
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
ld t1, 0(t0)
addi sp, sp, -8
sd t1, 0(sp)

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
add t0, t0, t1
addi sp, sp, -8
sd t0, 0(sp)

// get variable's value
ld t0, 0(sp)
addi sp, sp, 8
addi t6, zero, 8
mul t0, t0, t6
sub t0, fp, t0
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

ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// exit function body
ld ra, 432(sp)
ld fp, 424(sp)
addi sp, sp, 440
jr ra
