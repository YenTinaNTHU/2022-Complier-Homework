// enter funciton body
.global codegen
codegen:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456

// push num to stack
li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -64(fp)

// push num to stack
li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -72(fp)

// count the address value
li t0, 9
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

// call delay function
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// count the address value
li t0, 9
addi sp, sp, -8
sd t0, 0(sp)

// address
// call delay function
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay

// count the address value
li t0, 8
addi sp, sp, -8
sd t0, 0(sp)

// address
// count the address value
li t0, 9
addi sp, sp, -8
sd t0, 0(sp)

// address
// function invocation
ld a1, 0(sp)
addi sp, sp, 8
ld a0, 0(sp)
addi sp, sp, 8
jal ra, func1

addi sp, sp, -8
sd a0, 0(sp)
ld t0, 0(sp)
addi sp, sp, 8
sd t0, -80(fp)

// count the address value
li t0, 10
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
.global func1
func1:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456
sd a0, -24(fp)
sd a1, -32(fp)

// push value of pointer to stack
ld t0, -24(fp)
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
ld t0, -32(fp)
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

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -64(fp)

// count the address value
li t0, 8
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

// exit function body
ld a0, 0(sp)
addi sp, sp, 8
ld ra, 448(sp)
ld fp, 440(sp)
addi sp, sp, 456
jr ra
