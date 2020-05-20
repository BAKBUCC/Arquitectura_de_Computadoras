.data
#multiplicacion de numeros

    get_n1:.asciiz"coloque el primer numero:\n"
    get_n2:.asciiz"coloque el segundo numero:\n"
    resultado:.asciiz"la respuesta es \n"
.text
#pedir datos
li $v0,4
la $a0,get_n1
syscall

li $v0,5
syscall

move $t0,$v0

li $v0,4
la $a0,get_n2
syscall

li $v0,5
syscall

move $t1,$v0
#operacion
mult $t0,$t1

li $v0,10
syscall