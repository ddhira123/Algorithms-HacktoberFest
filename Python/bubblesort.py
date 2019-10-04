def bubbleSort(numberlist):
    for passednumber in range(len(numberlist)-1,0,-1):
        for i in range(passednumber):
            if numberlist[i]>numberlist[i+1]:
                temp = numberlist[i]
                numberlist[i] = numberlist[i+1]
                numberlist[i+1] = temp

numberlist = [10,5,52,56,53,44,116,112,20,41]
bubbleSort(numberlist)
print(numberlist)