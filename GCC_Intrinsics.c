#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t a = 5, b = 7;
    uint32_t result;

    // Sử dụng GCC Intrinsics cho phép nhân 32-bit không dấu
    result = __builtin_mul_overflow(a, b, &result) ? 0 : result;

    printf("Result: %u\n", result);

    return 0;
}