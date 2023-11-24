#include <stdio.h> 

int func(void) {
  int a=1,b=2,c;
    asm  ("movl %1, %%eax\n\t" "movl %2, %%ebx\n\t"
          "add %%eax,%%ebx\n\t" "movl %%ebx,%0\n\t"
          : "=r"(c)
          : "r"(a),"r"(b)
          : "%eax","%ebx"
          );
return c;
}

int func2(void) { 
  int a=1,b=2,c;
  asm  ("add %1,%2\n\t" "movl %2,%0\n\t"
        : "=r"(c)
        : "r"(a),"r"(b)
        : /* none */
        );
return c;
}

int main( ) {
  printf("%d %d", func(), func2() ); return 0;
}
