#include <immintrin.h>
#include<stdio.h>
int main() {
    unsigned int value = 0b10101010;
    int popcount = _mm_popcnt_u32(value);
    printf("bit counting: %d",popcount);
    //bit counting: 4
    return 0;
}