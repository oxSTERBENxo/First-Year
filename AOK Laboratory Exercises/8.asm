#Да се комплетира асемблерската програма така што да соодветствува на дадениот код во С. Да се користат целобројни променливи кои зафаќаат 4 бита.
#n=10;
#proizvod=1;
#for (i=0; i<10; i++){
#    proizvod=proizvod*a[i];
#    a[i]=proizvod;
#}

.data
    niza: .word 1, 3, 5, 7, 9

.text

    addi $s1, $zero, 5  #broj na elementi vo nizata
    addi $s2, $zero, 1  #proizvod
    addi $s3, $zero, 0  #brojac za ciklus
    la $s0, niza
    
loop:
    beq $s3, $s1, endLoop
    sll $t0, $s3, 2
    addi $t0, $t0, $s0
    lw $t1, 0($t0)
    mult $t1, $s2
    mflo $s2 
    sw $s2, 0($t0)
    addi $s3, $s3, 1
    j loop

endLoop:
li $v0, 10
syscall
