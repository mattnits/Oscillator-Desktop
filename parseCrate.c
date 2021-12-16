#include <stdio.h>
#include <stdlib.h>


void main() {
    unsigned char buffer[10];
    FILE *ptr;

    ptr = fopen("test.crate","rb");

    fread(buffer,sizeof(buffer),1,ptr); 

    for(int i = 0; i<10; i++) {
        printf("%u", buffer[i]); // prints a series of bytes
        char c = buffer[i];
        printf("%c\n", c);
    }
        
}