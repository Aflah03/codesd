#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

void print_time_usage() {
    struct rusage usage;

    // Get resource usage for the calling process
    getrusage(RUSAGE_SELF, &usage);

    // Print user and system time
    printf("User time: %ld.%06ld seconds\n",
           usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("System time: %ld.%06ld seconds\n",
           usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
}

int main() {
    // Print the current system date and time using `system()`
    printf("System date and time:\n");
    system("date");

    // Measure and print time usage before the loop
    printf("\nResource usage before the loop:\n");
    print_time_usage();

    // Perform a long-running loop
    printf("\nRunning a long loop...\n");
    volatile unsigned long long counter = 0;
    for (unsigned long long i = 0; i < 1000000000ULL; ++i) {
        counter += i;
    }

    // Measure and print time usage after the loop
    printf("\nResource usage after the loop:\n");
    print_time_usage();

    return 0;
}
