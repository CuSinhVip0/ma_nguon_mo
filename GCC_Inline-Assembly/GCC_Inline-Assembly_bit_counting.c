#include <stdio.h>

int main() {
    unsigned int value = 0b10101010;
    int popcount;

    asm (
        // Thực hiện popcnt assembly
        "popcnt %[value], %[popcount]"  
        // Output: popcount
        : [popcount] "=r" (popcount)    
        // Input: value
        : [value] "r" (value)            
    );

    printf("Popcount: %d\n", popcount);

    return 0;
}