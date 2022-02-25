  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #

.global hexasc
.global time2string
.global delay
.global enable_interrupt
.data
.align 2


.text
  # you can write your code for subroutine "hexasc" below this line
  #
hexasc:
andi    $v0, $a0, 15		# set register $v0 equal to the (4) least significant bits of $a0

sge    $t0, $v0, 10    		# set $t0 to 1 if register v0 ist greater than or equal to 10
beq    $t0, 1, hexascdone	# if register t0 has the value 1 jump to hexascdone

add    $v0, $v0, 0x30   	# adds 0x30 to $v0 to convert to ASCII for numbers

jr     $ra        		# returns v0 to main
nop            			# delay slot filler (just in case)

hexascdone:
add    $v0, $v0, 0x37    	#  converts v0 to ASCII for letters

jr    $ra       		#  returns v0 to main
nop            			# delay slot filler (just in case)`

delay:
	addi 	$t0, $0, 6731		# ms value

loop:
	ble	$a0, $0, stoploop	# if argrument is 0 or less branch to stop
	nop
	
	addi	$a0, $a0, -1		# decrease value of ms
	addi 	$t1, $0, -1		# reset value of i

for:
	addi	$t1, $t1, 1		# increase value of i
	ble	$t1, $t0, for		# count untill i = ms value
	nop
	j loop				# jump to label loop
	nop

stoploop:
	jr	$ra
	nop
	
time2string:
	PUSH	$s0
	PUSH	$s1
	PUSH	$ra		# push registers to stack since we will use several function calls
				# saving what is on them now
	add	$s0, $0, $a0	#contians adress of the string, timstr
	add	$s1, $0, $a1	#contains the time-info(0x5957)
	
	li	$t0, 0x00
	sb	$t0, 5($s0)	# put null byte last pos to mark end of string
	
	li	$t0, 0x3a	# load ':' into temp
	sb	$t0, 2($s0)	# store ':' in byte adress 2
	
	andi	$a0, $s1, 0xf	# mask the foru LSB of s1 and puts them in a0
	jal 	hexasc		# calls function hexasc
	nop
	sb	$v0, 4($s0)	#ladda in på byte adress 4
	
	andi	$t0, $s1, 0xf0	# maska igen fast till temp då vi måste shifta
	srl 	$a0, $t0, 4
	jal	hexasc
	nop
	sb	$v0, 3($s0)
	
	andi	$t0, $s1, 0xf00
	srl 	$a0, $t0, 8
	jal	hexasc
	nop
	sb	$v0, 1($s0)
	
	andi	$t0, $s1, 0xf000
	srl 	$a0, $t0, 12
	jal	hexasc
	nop
	sb	$v0, 0($s0)
	
	POP	$ra
	POP	$s1
	POP	$s0
	
	jr	$ra
	nop
	
enable_interrupt:
	ei			# utför ei instruktionen
	jr	$ra		# return to caller		
	nop			#delay slot just in case