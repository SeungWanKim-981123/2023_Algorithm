def NumTree(n):
  memo={}
  memo[0]=1
  memo[1]=1
  for i in range(2,n+1):
    for j in range(0,i):
      memo[i]=memo[j]*memo[n-j-1]
  return memo[n]
print(NumTree(2))