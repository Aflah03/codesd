#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_odd_numbers(int *arr, int size) {
    printf("Child (Odd): Odd numbers in the array:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void print_even_numbers(int *arr, int size) {
    printf("Child (Even): Even numbers in the array:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    pid_t odd_pid, even_pid;
    int arr[100], n;

    // Parent process inputs the array
    printf("Parent: Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Parent: Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Fork the first child process (for odd numbers)
    odd_pid = fork();

    if (odd_pid < 0) {
        perror("Fork failed for odd process");
        exit(1);
    } else if (odd_pid == 0) {
        // Child process for printing odd numbers
        print_odd_numbers(arr, n);
        exit(0);
    }
    else{

        // Parent process forks the second child process (for even numbers)
        even_pid = fork();

        if (even_pid < 0) {
            perror("Fork failed for even process");
            exit(1);
        } else if (even_pid == 0) {
            // Child process for printing even numbers
            // Wait for the odd process to finish
            waitpid(odd_pid, NULL, 0);
            print_even_numbers(arr, n);
            exit(0);
        }
    }

    // Parent process waits for both child processes to finish
    waitpid(odd_pid, NULL, 0);
    waitpid(even_pid, NULL, 0);

    printf("Parent: Both child processes have completed.\n");

    return 0;
}

