
#ifndef USE_MIPS_ASSEMBLY
#define USE_MIPS_ASSEMBLY
#include <mips/regdef.h>
#include <sys/syscall.h>

.text
.align 2
.globl compare

# t1 = posicion caracter actual en cadena 1
# t2 = posicion caracter actual en cadena 2


compare:
		subu sp,sp,16		# creo stack frame
		sw $fp,12(sp)
		sw gp,8(sp)
		move $fp,sp

		add t0, zero, zero	# result =0
		add t1, zero, a0
		add t2, zero, a1

nextchar:	
		#Cargo los elementos a comparar en t4 y t5
		lb t3, 0(t1)
		lb t4, 0(t2)
	
		#Voy a pasar todas las mayusculas a minusculas para que compare sea case insenstive como en C
		
		addi t5, t3, -91
		bgtz t5, aMinusculas2
		addi t5, t3, -64
		bltz t5, aMinusculas2
		addi t3, t3, 32

aMinusculas2:	addi t5, t4, -91
		bgtz t5, comparacion
		addi t5, t4, -64
		bltz t5, comparacion
		addi t3, t4, 32


		#Comparo caracter para ver si es final del string
comparacion:	beqz t3, fincadena1
		beqz t4, fincadena2

continue:	sub t0, t3, t4		# cadena1[i] - cadena2[i]	
		add t1, t1, 1		#NO VA sll x,y,2: por q char es un byte
		add t2, t2, 1

		beqz t0, nextchar	
		j fin
		

fincadena1:	beqz t4, fin
		add t0, zero, -1
		j fin

fincadena2:	add t0, zero, 1
		j fin

fin:		##Comienzo retorno
		addi v0, t0, 0

		move sp, $fp
		lw gp, 8(sp)
		lw $fp, 12(sp)
		addiu sp, sp, 16
		jr ra			#ra = return address es la direccion a la q quiero volver luego de llamar la funcion

#endif
