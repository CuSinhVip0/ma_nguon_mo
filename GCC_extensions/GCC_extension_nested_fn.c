#include <stdio.h>

int main() {
    int outerFunction() {
        int innerFunction() {
            return 42;
        }

        return innerFunction();
    }
    printf("%d",outerFunction());
    return 0;
}