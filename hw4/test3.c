#include <stdio.h>

#define LEN 128

int main() {
    int myAsciiList[LEN] = {0};
    for(;;) {
        char ch;
        int rv = scanf("%c", &ch);
        if(rv == EOF)
            break;
        if(!rv) {
            printf("scanf failed\n");
            break;
        }
        
        if((unsigned) ch >= LEN) {
            printf("ch is too large\n");
            break;
        }
        myAsciiList[(unsigned) ch]++;
    }
    for(size_t i = 0; i < LEN; i++) {
        if(myAsciiList[i])
            printf("%c: %d\n", (char) i, myAsciiList[i]);
    }
}