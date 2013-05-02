#ifndef USE_MIPS_ASSEMBLY
#define USE_MIPS_ASSEMBLY
#include <mips/regdef.h>
#include <sys/syscall.h>

.text
.align 2
.globl swap



swap:
		subu sp,sp,16		# creo stack frame
		sw $fp,12(sp)
		sw gp,8(sp)
		move $fp,sp

		#Guardo los parametros recibidos en fp
		sw a0,16($fp)		# guardo los primeros 4 parametros con la llamo a checksum
		sw a1,20($fp) 		# 20-16 = 4Bytes=32bits
		sw a2,24($fp)

		##Guardo en variables auxiliares las direcciones de memoria a intercambiar
		lw t0, 16($fp)		#en 16 esta el words
		lw t1, 20($fp)		#en 20 esta el i
		lw t2, 24($fp)		#en 20 esta el j

		##Realizo el intercambio
		#t3 = direccion de fp+(i*4)
		#t4 = direccion de fp+(j+4)
		sll t1, t1, 2
		sll t2, t2, 2
		addu t1, t1, t0
		addu t2, t2, t0


		#Cargo los elementos a intercambiar en t3 y t4
		lw t3, 0(t1)
		lw t4, 0(t2)

		#Guardo los elementos de manera intercambiada
		sw t4, 0(t1)
		sw t3, 0(t2)


		lw v0, 0(t2) 

		##Comienzo retorno
		move sp, $fp
		lw gp, 8(sp)
		lw $fp, 12(sp)
		addiu sp, sp, 16
		jr ra			#ra = return address es la direccion a la q quiero volver luego de llamar la funcion

#endif
