#include <stdio.h>

double calculate_cosine(double x) {
    double result;
    asm volatile(
        "fldl %[input]\n\t"       
        "fcos\n\t"                
        "fstpl %[result]\n\t"     
        : [result] "=m" (result)  
        : [input] "m" (x)         
    );
    return result;
}

int main() {
    double angle = 45.0;
    double result = calculate_cosine(angle);
    printf("cos(%f) = %f\n", angle, result);
    return 0;
}