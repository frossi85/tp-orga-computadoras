#ifndef USE_MIPS_ASSEMBLY
#define USE_MIPS_ASSEMBLY
#include <mips/regdef.h>
#include <sys/syscall.h>

.text
.align 2
.globl shellsort


shellsort:	subu sp,sp,16		# creo stack frame
		sw $fp,12(sp)
		sw gp,8(sp)
		move $fp,sp

		#Guardo los parametros recibidos en fp
		sw a0,16($fp)		# words = char **
		sw a1,20($fp) 		# size

		#Guardo los parametros cargados en fp a variables temporales
		lw t6, 16($fp)		#en 16 esta el words
		lw t7, 20($fp)		#en 20 esta el size

		#Iniciaizo variables locales
		srl t0, t7, 2		# intervalo = size/2
		li t1, 0		# k
		li t2, 0		# j
		li t3, 0		# i
		li t4, 0		# sAux

		#Resto uno al valor de size para la comparacion del for i < size
		sub t7, 1

		#while(intervalo > 0)
loop1:		bgt t0, 0, loop2	#branch grater than, salta si t1 es mayor a t0
		j fin

		#for(i = intervalo-1; i < arraysize; i++)	
loop2:		bge t3, t7, endloop2	# mientras i <= size - 1, bge=branch greater than or equal
		

		sub t2, t3, t0		#j = i - intervalo;

		#while(j >= 0)
loop3:		bge t2, 0, loop3task
		j loop2

loop3task:	add t1, t2, t0		#k = j + intervalo;

		#Para comparar cadenas, la forma más sencilla es iterar sobre cada caracter de cada cadena, y restarlos. Si el resultado es 0, son 
#iguales. Si no, a continuación, si el resultado es> 0, entonces la primera cadena es mayor de que la otra cadena, de lo contrario la segunda cadena es inferior y #habria que intercambiarlas. Si te quedas sin alguna de las cadenas antes que el otro, y son iguales hasta llegar a ese punto, la cadena más corta es menor que el que #más.
		#CARGO LAS CADENAS A COMPARAR
		#words[j]
		##Guardo en variables auxiliares las direcciones de memoria a intercambiar
		#words = t6
		#Guardo i y j por q las voy a modificar y no las quiero perder
		sw t1, 0($fp)
		sw t2, 4($fp)
		
		sll t1, t1, 2
		sll t2, t2, 2
		addu t1, t1, t6
		addu t2, t2, t6

		#Cargo los strings a comparar
		lw t8, 0(t1)		#OPTIMIZAR CODIGO PARA ISAR MENOS ti
		lw t9, 0(t2)

		
		#Falta esto
		#Si compare(words[j], words[k]) > 0
		#{
		#	sAux = words[j];
		#	words[j] = words[k];
		#	words[k] = sAux;
		#}
		#sino
		#	j = 0;

		sub t2, t2, t0		#j = j - intervalo;
		j loop3


endloop2:	srl t0, t0, 2		#intervalo = intervalo / 2;
		addi t3, t3, 1		#i++
		j loop1



		##Comienzo retorno
fin:		move sp, $fp
		lw gp, 8(sp)
		lw $fp, 12(sp)
		addiu sp, sp, 16
		jr ra			#ra = return address es la direccion a la q quiero volver luego de llamar la funcion

#endif
