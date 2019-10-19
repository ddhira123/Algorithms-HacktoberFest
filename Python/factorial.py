ans = 1
n = int(input())
if(n<0):
  print("Invalid")
else:  
    for i in range(1,n+1):
        ans *= i
    print(ans)
