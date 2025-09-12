#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// The maximum number of characters for a command
#define MAX_COMMAND_LENGTH 1024
// The maximum number of tokens (arguments) for a command
#define MAX_TOKENS 64

int tokenize(char *input, char *tokens[]) {
    int token_count = 0;
    char *token = strtok(input, " \t\n\r"); // Split by space, tab, newline, carriage return

    while (token != NULL && token_count < MAX_TOKENS - 1) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " \t\n\r");
    }
    tokens[token_count] = NULL;
    return token_count;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];

    while (1) {
        // Print the prompt
        printf("minishell> ");
        fflush(stdout); 

        // Read a line of input from the user
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n"); 
            break;
        }

        int token_count = tokenize(input, tokens);

        if (token_count == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror(tokens[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
