.data
	base: .word 0
	expoente: .word 0
	modulo: .word 0
	
	string:                 .asciiz "A exponencial modular "
	string1:                .asciiz " elevado a "
	string2:                .asciiz " (mod "
	string3:                .asciiz ") eh "
	stringPonto:            .asciiz "."
	stringEntradaInvalida:  .asciiz "Entradas invalidas."
	stringModuloNaoPrimo:   .asciiz "O modulo nao eh primo."
	space:                  .asciiz "\n"
.text

main:
	#Leitura das Entradas:
	
	#Leitura Base
 	li $v0, 5
 	sw $v0, base
 	syscall
 	move $s0, $v0

 	#Leitura Expoente
 	li $v0, 5
 	sw $v0, expoente
 	syscall
 	move $s1, $v0
 	
 	#Leitura Modulo
 	li $v0, 5
 	sw $v0, modulo
 	syscall
 	move $s2, $v0	
	
	
	#Verificacao da Validacao das Entradas:
	#	1 - Entradas devem estar no intervalo (0 < entrada <= 65535);
	#	2 - O modulo deve ser um numero primo.
	
	addi $t0, $zero, 32767 #Preparando $t0 para comparar com as entradas e constatar se sao menores que 65535
	addi $t0, $t0, 32767
	addi $t0, $t0, 2 # t0 -> 32767 + 32767 + 2 = 65356 
	

	#	1 - Entradas Válidas:

	#Verificação Base:
	slt $t3, $0, $s0 #Verificar se a base eh maior que 0;
	beq $t2, $t3, imprimirErroEntradaInvalida #Caso seja menor ou igual a 0, imprimirErroEntradaInvalida;
	slt $t3, $s0, $t0 #Verificar se a base eh menor que 65536;
	beq $t3, $zero, imprimirErroEntradaInvalida #Caso seja maior que 65535, imprimirErroEntradaInvalida.
	
	#Verificação Expoente:
	slt $t3, $0, $s1 #Verificar se o expoente eh maior que 0;
	beq $t2, $t3, imprimirErroEntradaInvalida #Caso seja menor ou igual a 0, imprimirErroEntradaInvalid;
	slt $t3, $s1, $t0 #Verificar se o expoente eh menor que 65536;
	beq $t3, $zero, imprimirErroEntradaInvalida #Caso seja maior que 65535, imprimirErroEntradaInvalida.
	
	#Verificação Modulo:
	slt $t3, $0, $s2 #Verificar se o modulo eh maior que 0;
	beq $t2, $t3, imprimirErroEntradaInvalida #Caso seja menor ou igual a 0, imprimirErroEntradaInvalida;
	slt $t3, $s2, $t0 #Verificar se o modulo eh menor que 65536;
	beq $t3, $zero, imprimirErroEntradaInvalida #Caso seja maior que 65535, imprimirErroEntradaInvalida.
	
	
	#	2 - Modulo Primo:

	addi $t0, $zero, 256 #Limite do laco forPrimoMaior
	add $t6, $zero, $s2  #Limite do laco forPrimoMenor
	li $t4, 3#Indice do laco forPrimoMaior
	
	li $t5, 0 #Contador
	
	#Verificar se o Modulo eh par ou impar:
	li $t2, 2 #$t2 igual a 2
	div $t3,$s2,$t2 #divisao entre o modulo e o numero 2($t2)
 	mfhi $t7 #resto da divisao
 	
 	bne $t7, $0, moduloImpar #Se resto da divisao($t7) for diferente de 0, ou seja, impar, entra em moduloImpar
		jal moduloPar #Se resto da divisao($t7) for igual a 0, ou seja, par, entra em moduloPar
		
	moduloPar:
 		
 		slt $t1, $t2, $s2 #Verifica se modulo eh maior ou menor que 2($t2)
 		bne $t1, $0, impressaoErroPrimo #Se modulo for maior que 2, imprimirErroEntradaInvalida
			jal moduloImpar #Se modulo for menor ou igual a 2, entra moduloImpar

	moduloImpar:

		slt $t1, $s2, $t0 #Verifica se modulo eh maior ou menor que 256($t0)
		bne $t1, $0, forPrimoMenor256 #Se modulo for menor que 256($t0), entra em forPrimoMenor256
			li $t4, 3#Indice do laco forPrimoMaior
			jal forPrimoMaior256 #Se modulo for maior que 256($t0), entra em forPrimoMaior256
		
		li $v0, 10 #saida, fim de programa na Main
 		syscall	
	
	
	li $v0, 10 #saida, fim de programa na Main
 	syscall
	
	
forPrimoMenor256:
 	
 	li $t4, 1 #$t4 igual a 1
 	beq $t4, $t6, validacaoPrimo #Se modulo for igual a 1($t4), entra em validacaoPrimo
 	
 	li $t4, 2 #$t4 igual a 2
 	beq $t4, $t6, validacaoPrimo #Se modulo for igual a 2($t4), entra em validacaoPrimo
 		
 	li $t4, 3 #$t4 igual a 3, indice do laco auxforPrimoMenor

	#Laco for de 3 até modulo($t6) com incremento de +2 no indice($t4):
 	auxforPrimoMenor:
 		beq $t4, $t6, validacaoPrimo #Caso indice($t4) != modulo($t6), laco auxforPrimoMenor funciona
									 #Caso indice($t4) == modulo($t6), entra em validacaoPrimo
 	
 		div $t3,$s2,$t4 #divisao entre o modulo e o indice ($s2 / $t4)
	 	mfhi $t7 #resto da divisao
 	
	 	add $t4,$t4,2 #incremento de indice($t4)
	 	
 		beq $t7, $zero, auxFor1 #Se resto($t7) for igual 0, entra auxFor1
 			j auxforPrimoMenor #Se resto($t7) for diferente de 0, retorna a fazer laco auxforPrimoMenor
 	
		auxFor1:
			add $t5,$t5,1 #Incrementa o contador($t5)
			j auxforPrimoMenor #Retorna a fazer laco auxforPrimoMenor


#Laco for de 3 até 255(Ultimo impar menor que 256) com incremento de +2 no indice($t4):
forPrimoMaior256:
 
 	beq $t4,257,validacaoPrimo #Caso indice($t4) != 257, laco forPrimoMaior256 funciona
							   #Caso indice($t4) == 257, entra em validacaoPrimo
 	
 	div $t3,$s2,$t4 #divisao entre o modulo e o indice ($s2 / $t4)
 	mfhi $t7 #resto da divisao
	
	add $t4,$t4,2 #incremento de indice ($t4)
	 	
	beq $t7, $zero, auxFor2 #Se resto($t7) for igual 0, entra auxFor2
 		j forPrimoMaior256 #Se resto($t7) for diferente de 0, retorna a fazer laco forPrimoMaior256
 	
 	auxFor2:
 		add $t5,$t5,1 #Incrementa o contador($t5)
 		jal forPrimoMaior256 #Retorna a fazer laco forPrimoMaior256
	

#Final da verificacao se modulo eh primo:	
validacaoPrimo:
 	
 	li $t4, 1 #$t4 igual a 1
 	beq $t6, $t4, impressaoErroPrimo #Se modulo for igual a 1($t4), entra em impressaoErroPrimo
 	
 	beq $t5, $0, exponenciacao #Se contador for igual a 0, entra exponenciacao
		jal impressaoErroPrimo #Se contador for diferente que 0, impressaoErroPrimo
 	
 	#saida
 	li $v0, 10
 	syscall	


exponenciacao:
	
 	#calculo exponencial
 	addi $t1, $zero, 0 #indice
 	addu $t2,$zero, $s0 #FAT
 	addi $t3,$zero, 1 #FatFinal
 	add $t5,$zero,$s1 #$t5 recebe $s1, pois precisamos do valor de $s1 intacto
 	
forExponenciacao:
	#for i=0 até menor que 16 (16bits)
 	
 	beq $t1,16,Saida #for i=0 até menor que 16
 	
 	and $t0,$t5,0x01
 	
 	srl $t5,$t5,1
 	
 	beq $t1,0,primeiroCaso #i=0
 	
 	multu $t2,$t2	#FAT = FAT*FAT
 	mflo $t2
 	divu $t2,$s2		#FAT = FAT*FAT/modC
 	
 	mfhi $t4
 	
 	add $t2,$zero,$t4	#FAT = FAT*FAT % modC
 	
 	addi $t1,$t1,1
 	
 	bne $t0,$zero,multipl	#se t0 for 1 entra em multiplicacao
 		j forExponenciacao 


 primeiroCaso:
 	add $t2,$zero, $t2	#FAT = FAT
 	
 	addi $t1,$t1,1
 	
 	bne $t0,$zero,multipl	#se t0 for 1 entra em multiplicacao
 		j forExponenciacao 


 multipl:
 	multu $t2,$t3	#FatFinal = FAT*FatFinal
 	mflo $t3
 	divu $t3,$s2		#FAT*FatFInal/modC
 	
 	mfhi $t4
 	
 	add $t3,$zero,$t4      #FAT*FatFinal % modC
 	
 	j forExponenciacao 


#Impressao do Resultado (base^expoente) mod modulo:
Saida:
 	
	li $v0, 4
 	la $a0, string
 	syscall
 	
 	li $v0, 1
 	move $a0, $s0
 	syscall
 	
 	li $v0, 4
 	la $a0, string1
 	syscall
 	
 	li $v0, 1
 	move $a0, $s1
 	syscall
 	
 	li $v0, 4
 	la $a0, string2
 	syscall
 	
 	li $v0, 1
 	move $a0, $s2
 	syscall
 	
 	li $v0, 4
 	la $a0, string3
 	syscall
 	
 	li $v0, 1
 	move $a0, $t3
 	syscall
 	
 	li $v0, 4
 	la $a0, stringPonto
 	syscall
 	
 	li $v0, 4
 	la $a0, space
 	syscall
 	
	#saida
	li $v0, 10
 	syscall
 	
 
#impressao String Entradas Invalidas
imprimirErroEntradaInvalida:
 	li $v0, 4	
 	la $a0, stringEntradaInvalida
 	syscall
 	
 	#impressao space
 	li $v0, 4
 	la $a0, space
 	syscall
 	
 	li $v0, 10 #saida
 	syscall
 	
 	
#impressao String Modulo Nao Primo
impressaoErroPrimo:

	li $v0, 4
 	la $a0, stringModuloNaoPrimo
 	syscall
 	
 	#impressao space
 	li $v0, 4
 	la $a0, space
 	syscall
 	
 	#saida
 	li $v0, 10
 	syscall
