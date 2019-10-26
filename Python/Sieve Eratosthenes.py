from math import sqrt
def sieveEratosthenes(n):
       prime=[1]*(n+1)
       prime[0]=0
       prime[1]=0
       for i in range(2,int(sqrt(n))+1):
              j=2
              if prime[i]==1:
                     while(i*j<=n):
                            prime[i*j]=0
                            j+=1
       return prime
from collections import deque
for i in range(int(input())):
       n=int(input())
       a=sieveEratosthenes(n)
       pri=deque()
       for i in range(2,n+1):
              if a[i]==1:
                     pri.append(i)
       print(pri)
