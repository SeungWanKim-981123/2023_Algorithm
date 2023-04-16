#include <stdio.h>
#define N 209//공식을 통해서 피보나치 숫자가 209자리의 수라는 것을 알았음.
void print_digit(char d[N])
{
    int i=0;
    while (d[i++]==0);//일단 0이 들어가있는 배열인데 이걸 0이 아닐때까지 순회함. 즉, 시작점을 잡아준다는 의미임.
    while(i<N) printf("%d",d[i++]);//문자로 이루어진 배열은 그 자체로는 별 의미가 없고 출력을 정수로 뽑아주는 것임.
}

void add_digits(char aa[N],char bb[N])//함수의 원형을 봤을 때, 
{
    int i=0;
    int carry=0;
    int j,s;
    while (aa[i++]==0);//기존의 배열 aa에서 0이 아니면 뛰쳐나옴.
    for(j=N-1;j>=i-1;j--)//bb배열에 최종적으로 저장을 한다.
    {
        if((s=carry+aa[j]+bb[j])>9){
            bb[j]=s-10;
            carry=1;//캐리가 발생하는 것.
        }
        else{
            bb[j]=s;
            carry=0;
        }
    } 
}
int fibo(int n)
{
    int i;//for문을 돌리기 위한 i에 해당함.
    int storingArray[209];
    storingArray[0]=0;
    if(n>0)
    {
        storingArray[1]=1;
        for (i = 2; i < n; i++)
        {
            storingArray[i]=storingArray[i-1]+storingArray[i-2];
        } 
    }
    return storingArray[n];
}
int main()//ascii코드로 0은 Null을 의미한다는 것이 포인트이다.
{//for문을 돌린다. 1000개의 결과치를 저장할 무언가가 필요하다.
    char seungwanStoringArray[1000][209];
    char myarr1[209];
    char myarr2[209];
    myarr2[208]=1;
    seungwanStoringArray=myarr1;
    for (int i = 2; i <= 1000; i++)
    {
        add_digits(seungwanStoringArray[i-2],seungwanStoringArray[i-1]);
    }
    for (int i = 0; i < 1000; i++)
    {
        print_digit(seungwanStoringArray[i]);
    }
    return 0;
}