
#include <stdio.h>
#include <omp.h>
 
int main()
{
    int arr[16];
 
    // parallel for loop
    printf("Assign value of arr[]:\n");
#pragma omp parallel for
    for (int i = 0; i < 15; ++i) {
        arr[i] = i;
        printf("    Thread %d: arr[%d] = %d\n", 
                omp_get_thread_num(), i, arr[i]);
    }
 
    return 0;
}