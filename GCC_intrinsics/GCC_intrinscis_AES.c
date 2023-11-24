#include <wmmintrin.h>
#include<stdio.h>
#include<stdint.h>
void print_m128i(__m128i var) {
    uint32_t *val = (uint32_t*)&var;
    printf("0x%08x%08x%08x%08x\n", val[3], val[2], val[1], val[0]);
}
int main() {
    __m128i data = _mm_set_epi32(4, 3, 2, 1);
    __m128i key = _mm_set_epi32(8, 7, 6, 5);
    __m128i encrypted = _mm_aesenc_si128(data, key);
    printf("Encrypted: ");
    print_m128i(encrypted);
    //Encrypted: 0xcbf2f2524b7b7b545f77774d427c7c58
    return 0;
}