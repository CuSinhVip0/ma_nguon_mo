#include <stdio.h>
 
int main() {
 
    printf("File :%s\n", __FILE__ );
    //File :D:\c-examples\test.c
    printf("Date :%s\n", __DATE__ );
    //Date :Nov  2 2018
    printf("Time :%s\n", __TIME__ );
    //Time :14:21:08
    printf("Line :%d\n", __LINE__ );
    //Line :8
    printf("ANSI :%d\n", __STDC__ );
    //ANSI :1
 
}