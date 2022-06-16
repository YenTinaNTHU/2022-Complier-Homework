.global codegen
codegen:
addi sp, sp, -16
sd ra, 8(sp)
sd fp, 0(sp)
addi fp, sp, 16
li a0, 26
li a1, 1
jal ra, digitalWrite
li a0, 1000
jal ra, delay
li a0, 26
li a1, 0
jal ra, digitalWrite
li a0, 1000
jal ra, delay
ld ra, 8(sp)
ld fp, 0(sp)
addi sp, sp, 16
jr ra