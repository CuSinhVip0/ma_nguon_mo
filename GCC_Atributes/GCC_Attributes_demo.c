
#include <stdio.h>
#include <stdlib.h>

void die(const char *msg) __attribute__((noreturn));

int main() {
    int result = 0;

    if (result == 0) {
        die("An error occurred");
    }

    printf("This line will never be reached.\n");

    return 0;
}

void die(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    //exit(EXIT_FAILURE);
    // exit(EXIT_FAILURE);
    __builtin_unreachable();
}