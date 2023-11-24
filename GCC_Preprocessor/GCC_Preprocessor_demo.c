#include<stdio.h>
 
#define PI 3.14159265358979

// This is a function-like macro.
#define AREA(r) (PI*(r)*(r))
 
int main(){
    double pi_macro = PI;
    double area_macro = AREA(4.6);
    printf("pi_macrio = %f\n",pi_macro);
    printf("area_macro = %f\n",area_macro);
    return 0;
}
