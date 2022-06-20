// enter funciton body
.global codegen
codegen:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456

// push num to stack
li t0, 58
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 17
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
div t0, t1, t0
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

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
mul t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 10
addi sp, sp, -8
sd t0, 0(sp)

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

// address
ld t0, 0(sp)
addi sp, sp, 8
sd t0, -80(fp)

// push value of pointer to stack
ld t0, -80(fp)
addi sp, sp, -8
sd t0, 0(sp)

// push value of pointer to stack
ld t0, -80(fp)
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

// count the address value
li t0, -80
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// count the address value
li t0, -72
add t0, t0, fp
addi sp, sp, -8
sd t0, 0(sp)

// address
// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sd t1, 0(t0)

// push value of pointer to stack
ld t0, -80(fp)
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

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
div t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

// assign variable
ld t1, 0(sp)
addi sp, sp, 8
ld t0, 0(sp)
addi sp, sp, 8
sd t1, 0(t0)

// push num to stack
li t0, 29
addi sp, sp, -8
sd t0, 0(sp)

// call digitalWrite()
ld a0, 0(sp)
addi sp, sp, 8
li a1, 1
jal ra, digitalWrite

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

// call delay function
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// push num to stack
li t0, 29
addi sp, sp, -8
sd t0, 0(sp)

ld a0, 0(sp)
addi sp, sp, 8
li a1, 0
jal ra, digitalWrite

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

// push num to stack
li t0, 250
addi sp, sp, -8
sd t0, 0(sp)

// push num to stack
li t0, 8
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
mul t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
sub t0, t1, t0
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
