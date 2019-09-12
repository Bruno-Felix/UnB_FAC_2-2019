.data
	numeroA: .word 0
	numeroB: .word 0
	numeroC: .word 0
	
	stringNumeroA:	        .asciiz "NumeroA: "
	stringNumeroB:	        .asciiz "\nNumeroB: "
	stringNumeroC:	        .asciiz "\nNumeroC: "
	
	stringResultadoADD:     .asciiz "ADD: "
	stringResultadoSUB:     .asciiz "\nSUB: "
	stringResultadoAND:     .asciiz "\nAND: "
	stringResultadoOR:      .asciiz "\nOR: "
	stringResultadoXOR:     .asciiz "\nXOR: "
	stringResultadoMASK:    .asciiz "\nMASK: "
	stringResultadoSLL:     .asciiz "\nSLL("
	stringResultadoSRL:     .asciiz "SRL("
	stringFinalizarSRL_SLL: .asciiz "): "
	space:                  .asciiz "\n"

.text

main:
	#leitura numeroA
 	li $v0, 5
 	sw $v0, numeroA
 	syscall
 	move $s0, $v0

 	#leitura numeroB
 	li $v0, 5
 	sw $v0, numeroB
 	syscall
 	move $s1, $v0
 	
 	#leitura numeroC
 	li $v0, 5
 	sw $v0, numeroC
 	syscall
 	move $s2, $v0
 	
 	#Execução das Operações
 	add $t0, $s0, $s1
 	sub $t1, $s0, $s1
 	and $t2, $s0, $s1
	or  $t3, $s0, $s1
	xor $t4, $s0, $s1
 	and $t5, $s2, 31
 	srlv $t6, $s1, $t5  
 	sllv $t7, $s0, $t5 
 	
 	#Impressão stringResultadoADD
 	li $v0, 4
 	la $a0, stringResultadoADD
 	syscall
 	
 	#Impressão ADD
 	li $v0, 1
 	move $a0, $t0
 	syscall
 	
 	#Impressão stringResultadoSUB
 	li $v0, 4
 	la $a0, stringResultadoSUB
 	syscall
 	
 	#Impressão SUB
 	li $v0, 1
 	move $a0, $t1
 	syscall
 	
 	#Impressão stringResultadoAND
 	li $v0, 4
 	la $a0, stringResultadoAND
 	syscall
 	
 	#Impressão AND
 	li $v0, 1
 	move $a0, $t2
 	syscall
 	
 	#Impressão stringResultadoOR
 	li $v0, 4
 	la $a0, stringResultadoOR
 	syscall
 	
 	#Impressão OR
 	li $v0, 1
 	move $a0, $t3
 	syscall
 	
 	#Impressão stringResultadoXOR
 	li $v0, 4
 	la $a0, stringResultadoXOR
 	syscall
 	
 	#Impressão XOR
 	li $v0, 1
 	move $a0, $t4
 	syscall
 	
 	#Impressao stringResultadoMask
 	li $v0, 4
 	la $a0, stringResultadoMASK
 	syscall
 	
 	#Impressao MASK
 	li $v0,1
 	move $a0, $t5
 	syscall
 	
 	
 	#Impressao stringResultadoSLL
 	li $v0, 4
 	la $a0, stringResultadoSLL
 	syscall
 	
 	#Impressao MASK dentro do SLL - SLL(MASK)
 	li $v0,1
 	move $a0, $t5
 	syscall
 	
 	#Impressao stringFinalizarSRL_SLL
 	li $v0, 4
 	la $a0, stringFinalizarSRL_SLL
 	syscall
 	
 	
 	#Impressao SLL
 	li $v0,1
 	move $a0, $t7
 	syscall
 	
 	#impressao space
 	li $v0, 4
 	la $a0, space
 	syscall
 	
 	#Impressao stringResultadoSRL
 	li $v0, 4
 	la $a0, stringResultadoSRL
 	syscall
 	
 	#Impressao MASK dentro do SRL - SRL(MASK)
 	li $v0,1
 	move $a0, $t5
 	syscall
 	
 	#Impressao stringFinalizarSRL_SLL
 	li $v0, 4
 	la $a0, stringFinalizarSRL_SLL
 	syscall
 	
 	
 	#Impressao SRL
 	li $v0,1
 	move $a0, $t6
 	syscall
 	
 	#impressao space
 	li $v0, 4
 	la $a0, space
 	syscall
 	
 	#saida
 	li $v0, 10
 	syscall
