L = 20
.global main
main: save %sp, -96, %sp
mov %g0, %o0
mov 2, %l0
loop: subcc %l0, L, %g0
bg next_r
nop
add %o0, %l0, %o0
add %l0, 2, %l0
ba loop
nop
next_r: ret
restore
