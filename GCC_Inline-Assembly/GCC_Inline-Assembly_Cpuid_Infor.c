#include <stdio.h>

void cpuid(int *eax, int *ebx, int *ecx, int *edx) {
    asm volatile("cpuid"
                 : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
                 : "0" (*eax), "2" (*ecx));
}

int main() {
    int eax, ebx, ecx, edx;

    // Get Vendor ID
    eax = 0;
    cpuid(&eax, &ebx, &ecx, &edx);
    printf("Vendor ID: %.4s%.4s%.4s\n", (char*)&ebx, (char*)&edx, (char*)&ecx);

    // Get Family, Model, Stepping
    eax = 1;
    cpuid(&eax, &ebx, &ecx, &edx);
    int family = (eax >> 8) & 0xF;
    int model = (eax >> 4) & 0xF;
    int stepping = eax & 0xF;
    printf("Family: %d, Model: %d, Stepping: %d\n", family, model, stepping);

    // Check for SSE2 support
    if (edx & (1 << 26)) {
        printf("CPU supports SSE2\n");
    } else {
        printf("CPU does not support SSE2\n");
    }

    // Check for AVX support
    eax = 1;
    cpuid(&eax, &ebx, &ecx, &edx);
    if (ecx & (1 << 28)) {
        printf("CPU supports AVX\n");
    } else {
        printf("CPU does not support AVX\n");
    }

    return 0;
}