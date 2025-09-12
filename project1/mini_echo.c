#include <stdio.h>

// PART 1: MINI ECHO
void process (char *arg){
    printf("%s\n", arg);
}

int main (int argc, char *argv[]){
int i; 
for (i = 0; i < argc; i++){
    process(argv[i]);
}
}
// Unix will always have at least one parameter becasue the name of the 
// program is alwasy the first paramter 
