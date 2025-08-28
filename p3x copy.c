#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");   // program: "wc" (word count)
        myargs[1] = strdup("p3.c"); // argument: file to count
        myargs[2] = NULL;           // marks end of array
        execvp(myargs[0], myargs);  // runs word count
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;

    // Why do you think there are so many variants of the same basic call?
    //- there are many varients of the same basic call of exec() because 
    //- each varient has different way to take in parameters, but the output 
    //- should be relatively the same. 

    // execvp() means that a child does not have to do the same program as the parent. 
    // the system call allows it to run any program file 

    // execv() is similar to execvp() but the whole path of the file must be given
    // in the parameters

    // execlp() is similar to execvp() but the parameters are given in 
    // a list instead of an array

    // execl() is similar to execlp() but the whole path of the file must be given
    // in the parameters like execv()

    // execvpe() searches for the program in the PATH environment variable

