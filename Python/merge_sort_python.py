import math
import random

def mergesort(arr):
	if len(arr)>1:
		mid = len(arr)//2;
		left, right = arr[:mid], arr[mid:]
		mergesort(left)
		mergesort(right)
		i,j,k=0,0,0
		while i<len(left) and j<len(right):
			if left[i] <= right[j]:
				arr[k]=left[i]
				k,i=k+1,i+1
			elif right[j] <= left[i]:
				arr[k]=right[j]
				k,j=k+1,j+1
		while i<len(left):
			arr[k]=left[i]
			k,i=k+1,i+1
		while j<len(right):
			arr[k]=right[j]
			k,j=k+1,j+1

arr=[]
for i in range(10):
	arr.append(random.randint(0,500))

print("Unmerged : ",arr)
mergesort(arr)
print("Merged : ",arr)