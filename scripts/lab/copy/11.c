#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid; // Process ID

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child: I am %d, and my parent is %d\n", getpid(), getppid());
        exit(0);
    } else {
        // Parent process
        printf("Parent: I am %d, and my child is %d\n", getpid(), pid);

        // Wait for the child process to complete
        wait(NULL);
    }

    return 0;
}
