# Insertion Sort: Sorts the array in ascending order
# Time Complexity: O(N^2)

def insertion_sort(numbers):
    i = 0
    for i in range(i, len(numbers)):
        aux = numbers[i]
        j = i
        while ((j > 0) and (numbers[j-1] > aux)):
            numbers[j] = numbers[j-1]
            j -= 1
        numbers[j] = aux


numbers = [1, 2, 30, 4, 8, 3, 110, 8, 8, 7, 3, 6, 15];
insertion_sort(numbers);
print(numbers);