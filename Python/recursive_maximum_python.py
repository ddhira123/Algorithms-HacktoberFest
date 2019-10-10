import math

def findMax(n):

	if n==0 or n==1:
		return n

	else :
		return max((n//2+n//3+n//4),n)

def solution():

	n=int(input("Enter number of cases : "))
	arr=[]
	for i in range(n):
		val=int(input("Enter value : "))
		arr.append([val,findMax(val)])
	print("Maximal sum values : ")
	for item in arr:
		print(item[0],":",item[1])

solution()
