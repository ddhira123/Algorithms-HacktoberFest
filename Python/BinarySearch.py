def binarySearch(arr,n,a):
    top=0
    bot=n-1
    while top<=bot:
        mid=int((top+bot)/2);
        if  a==arr[mid]:
            return mid
        elif a<arr[mid]:
            bot=mid-1
        elif a>arr[mid]:
            top=mid+1
    return -1

