#include <wmmintrin.h>
#include <stdint.h>
#include <stdio.h>

void aes_encrypt(const __m128i data, const __m128i key, __m128i *result) {
    asm volatile (
        "movups %[data], %%xmm0\n"  // Load data into xmm0
        "movups %[key], %%xmm1\n"   // Load key into xmm1
        "aesenc %%xmm1, %%xmm0\n"   // AES encryption
        "movups %%xmm0, %[result]\n"// Store the result
        : [result] "=m" (*result)    // Output: result
        : [data] "m" (data),         // Input: data
          [key] "m" (key)            // Input: key
        : "%xmm0", "%xmm1"           // Clobbered registers
    );
}

int main() {
    __m128i data = _mm_set_epi32(4, 3, 2, 1);
    __m128i key = _mm_set_epi32(8, 7, 6, 5);
    __m128i result;

    aes_encrypt(data, key, &result);

    // Display the encrypted data
    printf("Encrypted: ");
    uint32_t *val = (uint32_t*)&result;
    printf("0x%08x%08x%08x%08x\n", val[3], val[2], val[1], val[0]);
    return 0;
}