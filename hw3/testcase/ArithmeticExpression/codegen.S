.global codegen
codegen:
addi sp, sp, -64
sd ra, 56(sp)
sd fp, 48(sp)
addi fp, sp, 64

li t0, 1
addi sp, sp, -8
sd t0, 0(sp)

li t0, 2
addi sp, sp, -8
sd t0, 0(sp)

li t0, 1
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
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -40(fp)

ld t0, -40(fp)
addi sp, sp, -8
sd t0, 0(sp)

li t0, 3
addi sp, sp, -8
sd t0, 0(sp)


ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
add t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

li t0, 2
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
sd t0, -48(fp)

ld t0, -48(fp)
addi sp, sp, -8
sd t0, 0(sp)

ld t0, -40(fp)
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
sd t0, -40(fp)
li a0, 26
li a1, 1
jal ra, digitalWrite

ld t0, -40(fp)
addi sp, sp, -8
sd t0, 0(sp)

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

li a0, 26
li a1, 0
jal ra, digitalWrite

ld t0, -48(fp)
addi sp, sp, -8
sd t0, 0(sp)

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

ld ra, 56(sp)
ld fp, 48(sp)
addi sp, sp, 64
jr ra
