#include <stdio.h>
#define LEN 128
int main()
{
    int mylist[LEN]={0};//일단 0으로 초기화
    for(;;)
    {
        char ch;//입력받을 문자 변수에 해당함. 근데 기본적으로 signed이므로 음양을 모두 표현한다고 보면 됨.
        int rv = scanf("%c", &ch);//입력을 받는다.
        if(rv == EOF)//EOF는 -1을 의미한다.
            break;
        if(!rv) {//rv가 0인 경우, 즉 scanf가 정상적으로 진행되지 않은 경우를 말한다.
            printf("scanf failed\n");
            break;
        } 
        if((unsigned) ch >= LEN) {
            printf("%d\n",ch);
            printf("ch is too large\n");
            break;
        }
        mylist[(unsigned) ch]++;
    }
    for (int i = 0; i < LEN; i++)
    {
        printf("%c: %d\n", (char) i, mylist[i]);
    }
    
    
    return 0;
}