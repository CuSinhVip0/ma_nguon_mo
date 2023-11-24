#include <iostream>
#include <omp.h>
 
int main()
{
    std::cout << "begin ";
 
#pragma omp parallel sections
    {
#pragma omp section
        {
            std::cout << "hello ";
            std::cout << "hello ";
            std::cout << "hello ";
        }
#pragma omp section
        {
            std::cout << "world ";
            std::cout << "world ";
            std::cout << "world ";
        }
    }
 
    std::cout << "end" << std::endl;
 
    return 0;
}