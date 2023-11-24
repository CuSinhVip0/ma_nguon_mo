#include <stdio.h>
#include <immintrin.h>

int main() {
     if (__builtin_cpu_supports("sse4.2")) {
        printf("SSE4.2 is supported.\n");
        
    } 
    else if (__builtin_cpu_supports("avx")) {
        printf("AVX is supported.\n");
    }else {
        printf("Neither AVX nor SSE4.2 is supported.\n");
    }

    return 0;
}