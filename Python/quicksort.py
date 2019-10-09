
'''
Algorithm used from pseudo-code from Introduction to Algorthms Third Edition, MIT Press
'''
def swap(A,i,j):
    x=A[i]
    A[i]=A[j]
    A[j]=x
    return A


def partition(A, p, r):
    x=A[r]
    i=p-1
    for j in (range(p,r)):
        if A[j] <= x:
            i+=1
            swap(A,i,j)#exchange A[i] with A[j]
    swap(A,i+1,r)#exchange A[i+1] with A[r]
    return i+1
def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)



if __name__ == '__main__':
    A=[2,8,7,1,3,5,6,4]
    print("Before sorting: ", end='')
    print(A)
    print()
    print("After sorting: ", end='')
    quicksort(A, 0, len(A)-1)
    print(A)