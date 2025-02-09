#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child: Replacing with myadder...\n");

        // Prepare arguments for myadder
        char *args[] = {"./myadder", "10", "20", NULL};

        // Replace the child process with myadder
        execvp(args[0], args);

        // If execvp fails
        perror("execvp failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent: Waiting for child to complete...\n");

        // Wait for the child process to complete
        wait(NULL);

        printf("Parent: Child process completed.\n");
    }

    return 0;
}

