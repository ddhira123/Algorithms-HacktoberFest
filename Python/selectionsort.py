def selection_sort(L):
    for i in range(len(L)-1):
        position_min = i
        for j in range(i, len(L)):
            if L[j] < L[position_min]:
                position_min = j
        if L[position_min] < L[i]:
            L[i],L[position_min] = L[position_min],L[i]