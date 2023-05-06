#include <stdio.h>
int main()
{
    /*c언어 소스파일을 컴파일 한 뒤 ./{실행파일명}<{넣어줄 파일명}으로 터미널에 입력하면 파일의 내용이 input으로 들어간다.
    어떠한 자료구조에 넣어주는 것이 효율적일 것인가? ==> 그냥 무식하게 하나하나 다 세는 방법도 있긴 함. 

    */
   int myAsciiList[128]={0,};//나올 때마다 더해줄 아스키 코드임.
   char gettingChar;//매번 입력받을 것을 말한다. 
   scanf("%c",&gettingChar);
   int indexingNum=gettingChar;
   myAsciiList[indexingNum]++;
   while(gettingChar!=EOF)
   {
        

   }
   
   
   return 0;
}