# enter funciton body
.global codegen
codegen:
addi sp, sp, -456
sd ra, 448(sp)
sd fp, 440(sp)
addi fp, sp, 456

# push num to stack
li t0, 65280
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -64(fp)

# push num to stack
li t0, 259
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -72(fp)

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

ld t0, 0(sp)
addi sp, sp, 8
ld t1, 0(sp)
addi sp, sp, 8
kadd8 t0, t1, t0
addi sp, sp, -8
sd t0, 0(sp)

ld t0, 0(sp)
addi sp, sp, 8
sd t0, -80(fp)

# push num to stack
li t0, 26
addi sp, sp, -8
sd t0, 0(sp)

# call digitalWrite()
ld a0, 0(sp)
addi sp, sp, 8
li a1, 1
jal ra, digitalWrite

# count the address value
li t0, -80
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

ld a0, 0(sp)
addi sp, sp, 8
li a1, 0
jal ra, digitalWrite

# count the address value
li t0, -80
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
