#include <stdio.h>
#define LEN 128

int main() {
    int myAsciiList[LEN] = {0};//초기화에 해당함.
    for(;;) {//for문을 다음과 같은 방식으로 무한 반복문의 형태로 쓸 수 있다. break를 써주면 해결됨.
        char ch;//입력받을 문자 변수에 해당함. 근데 기본적으로 signed이므로 음양을 모두 표현한다고 보면 됨.
        int rv = scanf("%c", &ch);//입력을 받는다.
        if(rv == EOF)//EOF는 -1을 의미한다.
            break;
        if(!rv) {//rv가 0인 경우, 즉 scanf가 정상적으로 진행되지 않은 경우를 말한다.
            printf("scanf failed\n");
            break;
        }
        if((unsigned) ch > LEN) {//인덱싱 자체를 넘어가는 것에 해당함.
            printf("ch is too large\n");
            break;
        }
        myAsciiList[(unsigned) ch]++;
    }
    for (int i = 0; i < 128; i++)
    {
       printf("%c: %d\n", (char) i, myAsciiList[i]);
    }
    return 0;
}