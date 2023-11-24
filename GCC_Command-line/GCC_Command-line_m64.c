#include <stdio.h>
int main() {
    //check environment
    if (sizeof(void*) == 4) 
        printf("32-bit environment\n");
    if (sizeof(void*) == 8) 
        printf("64-bit environment\n");

    printf("Size of int: %lu bytes\n", sizeof(int));
    return 0;
}