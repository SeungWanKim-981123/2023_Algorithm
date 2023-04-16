import math
def chain_mult(dlist):
    N=len(dlist)#리스트의 길이에 해당함.
    n=N-1#나중에 print_chain을 할때 활용할 n에 해당
    opt={}#최적의 계산 횟수를 저장할 딕셔너리임. 2차원의 배열처럼 생각하면 될듯
    kk={}#최적의 값을 보이는 k임.
    for i in range(1,N):
        opt[i,i]=0
        kk[i,i]=0
    for diff in range(1,N-1):
        for i in range(1,N-diff):
            min=100000
            j=i+diff
            for k in range(i,j):
                temp=opt[i,k]+opt[k+1,j]+dlist[i-1]*dlist[k]*dlist[j]
                if temp<min:
                    min=temp
                    kk[i,j]=k
            opt[i,j]=min#최적의 값을 기록.
    print("table of opt[i,j]\n")
    for i in range(1,N):
        for j in range(1,N):
            if i>j:
                print("   ",end=" ")
            else:
                print(repr(opt[i,j]).rjust(3),end=" ")
        print()
    print()
    print("table of k[i,j]")
    print()
    for i in range(1,N):
        for j in range(1,N):
            if i>j:
                print(" ",end=" ")
            else:
                print(kk[i,j],end=" ")
        print()
    def print_chain(i,j):
        if i==j:
            print("A",end="")
            print(i,end="")
            return
        if i==1 and j==n:
            print_chain(i,kk[i,j])
            print_chain(kk[i,j]+1,j)
            print(")",end="")
    print()
    print("optimal chained matrix multiplication")
    print()
    print_chain(1,n)

chain_mult([5,2,8,3,5,6,5,4])