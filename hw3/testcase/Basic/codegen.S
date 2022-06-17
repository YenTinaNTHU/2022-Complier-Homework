.global codegen
codegen:
addi sp, sp, -32
sd ra, 24(sp)
sd fp, 16(sp)
addi fp, sp, 32
li a0, 26
li a1, 1
jal ra, digitalWrite
li t0, 1000
addi sp, sp, -8
sd t0, 0(sp)
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay
li a0, 26
li a1, 0
jal ra, digitalWrite
li t0, 1000
addi sp, sp, -8
sd t0, 0(sp)
ld a0, 0(sp)
addi sp, sp, 8
jal ra, delay
ld ra, 24(sp)
ld fp, 16(sp)
addi sp, sp, 32
jr ra