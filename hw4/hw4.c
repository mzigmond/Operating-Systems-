#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int x = 100;
    printf("Before fork: x = %d\n", x);
    int pid = fork();
    if (pid < 0){
        printf ("Fork failed\n");
        return 1;
    } else if (pid == 0){
        printf ("child: x = %d\n", x);
        x += 100;
        printf("Child process after fork: x = %d\n", x);
    }else{
        printf ("parent: x = %d\n", x);
        x += 100;
        printf("Parent process after fork: x = %d\n", x);
    }
    return 0;
}


/*
1. What value is the variable in the child process? 
- After the child process is created and after it runs, the value 
- of x in the child process is 200. 
2. What happens to the variable when both the child and parent change the value of x? 
- The parent and child processes are different and can 
- increase or decrese the value of x without affecting the other process. 
*/