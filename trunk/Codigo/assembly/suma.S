#ifndef USE_MIPS_ASSEMBLY
#define USE_MIPS_ASSEMBLY
#include <mips/regdef.h>
#include <sys/syscall.h>

.text
.align 2
.globl sumador



sumador:
		subu sp,sp,16		# creo stack frame
		sw $fp,12(sp)
		sw gp,8(sp)
		move $fp,sp

		sw a0,16($fp)		# guardo los primeros 4 parametros con la llamo a checksum
		sw a1,20($fp) 		# 20-16 = 4Bytes=32bits

		li t0,0 		#en t0 guardo la suma de los enteros del array
		sw t0, 0($fp) 		#transfiere de registro al fp, la primer variable que declare dentro de la funcion
		sw zero, 4($fp)		#4bytes es unregistro, entonces guardo el primer valor apartir del fp 4 bytes = un registro
loop:		lw t0, 20($fp)		#en 20 esta el size
		lw t1, 4($fp)		#guarda el valor de i para el for(), en ASM i va de 0,4,8,12,...,n etc
	
		subu t0, t0, 1		#Para simular el for el i < size, sino lo hago hace i <= size
		
		bgt t1, t0, fin		#branch grater than, salta si t1(i) es mayor a t0(suma)
		lw t1, 4($fp)		#POR Q?? PREGUNTAR EN LISTA??
		sll t1, t1, 2		#shift left logical, para incrementar a i de a 4, ver de pasarlo al final de loop
		lw t2, 16($fp)		#es el array de enteros, int * values
		addu t3,t2,t1		#Guarda la direccion en memoria para acceso directo en el array de enteros al elemento i, equivalente a values+i
		lw t0, 0($fp)		#cargo en t0 el acumulador (donde guardo la suma)
		lw t4, 0(t3)		//CARGA EN t4 lo que hay en la posicion de memoria guardada en t3
		addu t0, t0, t4		#realizo la suma en t0
		sw t0, 0($fp)
		lw t0, 4($fp)		#cargo el i en valor decimal: 0,1,2,3, etc
		addiu t0, t0, 1		#++i
		sw t0, 4($fp)
		j loop
fin:		lw v0, 0($fp) 		#v0 = values return for function, 0($fp) esta el valor de la suma


#test
		#lw v0, 20($fp) 	#test
		
		#lw t2, 16($fp)
		#lw v0, 0(t3)
#endtest
		move sp, $fp
		lw gp, 8(sp)
		lw $fp, 12(sp)
		addiu sp, sp, 16
		jr ra			#ra = return address es la direccion a la q quiero volver luego de llamar la funcion

#endif
