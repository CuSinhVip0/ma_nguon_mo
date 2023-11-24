#include <stdio.h>

int main() {
    int x = 10;
    double z = 15.0;
    typeof(x) y = 20;
    printf("Kiểu dữ liệu của x va y là: %s\n", 
    __builtin_types_compatible_p(typeof(y),typeof(x)) 
        ? "int" : "Không xác định");
    printf("Kiểu dữ liệu của z va y là: %s\n", 
    __builtin_types_compatible_p(typeof(y),typeof(z)) 
        ? "int" : "Không xác định");
    return 0;
}