#include <stdio.h>
int get_max_cpuid_call(void) { 
  int retval = 0;
    asm  ("xor %%eax, %%eax\n\t" "cpuid\n\t"
    "movl %%eax,%0\n\t"
    : "=r"(retval)
    : /* no inputs */
    : "%eax"
    );
  return retval;
}

int print_ids(void) { 
  int id;
  int ax;
  for( ax=0; ax < get_max_cpuid_call(); ++ax ) {
    asm  ( "movl %1, %%eax\n\t" "cpuid\n\t"
    "movl %%eax,%0\n\t"
    : "=r"(id)
    : "r"(ax)
    : "%eax" );
  printf("ID[%d] = %d\n", ax, id );
  }
}
void cpuid(int *eax, int *ebx, int *ecx, int *edx) {
    asm volatile("cpuid"
                 : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
                 : "0" (*eax), "2" (*ecx));
}



unsigned int get_cpu_information(void) { 
  unsigned int info = 0x0;
  int param = 1;
    asm  ( "movl $1, %%eax\n\t" "cpuid\n\t"
    "movl %%eax,%0\n\t"
    : "=r"(info)
    : "r"(param)
    : "%eax" ); 
    return info;
}
void print_cpu_information(unsigned int param) { 
  printf("\n CPU Information = %d", param); 
  printf("\n Stepping number = %d", (param & 7) );
  printf("\n Model number = %d", (param & 0x00F0) >> 4 ); 
  printf("\n Family number = %d",(param & 0x0F00) >> 8 ); 
  printf("\n Processor type= %d",(param & 0xA000) >> 12);
}

int main() {
  printf("Max CPUID call = %d\n", get_max_cpuid_call() ); 
  print_ids();
  print_cpu_information( get_cpu_information() ); printf("\n");

  int a,b,c,d;
  a=0;
  c=0;
  cpuid(&a,&b,&c,&d);
  printf("EAX: %08x\n", a);
    printf("EBX: %08x\n", b);
    printf("ECX: %08x\n", c);
    printf("EDX: %08x\n", d);

  return 0;
}
