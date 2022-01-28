.table
int IL_s0[100] = 
int IL_s0_size = 0
float FL_s0[100] = 
int FL_s0_size = 0
int i_s1
int new_s1[100] = 
int new_s1_size = 0
int elem_s2
char _s0[] = "Digite o elemento da lista: "
char _s1[] = "Digite os número de elementos da lista: "
int n_s5
float FL10_s5[100] = 
int FL10_s5_size = 0
float AUXL_s6[100] = 
int AUXL_s6_size = 0
int n_s6
char _s2[] = " "
char _s3[] = " "
char _s4[] = "A nova lista tem "
char _s5[] = " elementos."
char _s6[] = "A nova lista não possui elementos."

.code
35_s6
mov $999, 0
Jump37:
mov $16, &_s6
mov $16, $16[$999]
print $16
sub $1000, $1000, 1
add $999, $999, 1
brnz Jump37, $1000
print '\n' 
Jump36:
return 0
return

main:
call _main, 0