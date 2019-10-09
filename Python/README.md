# Factorial



In mathematics, the factorial of a non-negative integer `n`, 
denoted by `n!`, is the product of all positive integers less 
than or equal to `n`. For example:

```
5! = 5 * 4 * 3 * 2 * 1 = 120
```

| n     | n!                          | 
| ----- | --------------------------: |
| 0     | 1                           |
| 1     | 1                           |
| 2     | 2                           |
| 3     | 6                           |
| 4     | 24                          |
| 5     | 120                         |
| 6     | 720                         |
| 7     | 5 040                       |
| 8     | 40 320                      |
| 9     | 362 880                     |
| 10    | 3 628 800                   |
| 11    | 39 916 800                  |
| 12    | 479 001 600                 |
| 13    | 6 227 020 800               |
| 14    | 87 178 291 200              |
| 15    | 1 307 674 368 000           |

## References

[Wikipedia](https://en.wikipedia.org/wiki/Factorial)

# Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

Third Pass:
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

# Selection Sort 

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

# QuickSort
The QuickSort algorithm applies the divide and conquer paradigm. Here is the three-step divide-and-conquer process for sorting a typical subarrayA[p...r]
## Divide:
Partition the array A[p..r] into two (possibly empty) subarrays A[p..q-1] and A[q+1..r] such that each element of A[p..q-1] is less than or equal to A[q], which is , in turn, less than or equal to each element of A[q+1..r]. Compute the index q as part of this partitioning procedure.QuickSort
## Conquer:
Sort the two subarrays A[p..q-1] and A[q+1..r] by recursive calls to quicksort.
## Combine:
Becouse the subarrays are already sorted, no work is needed to combine them: the entire array A[p..r] is now sorted.

## Worst Case Running Time:
The worst-case split at every level of recursion in quicksort produces a \theta (n^2) running time. The running time is dominated by the partition procedure.

The
## References
Introduction to Algorithms, Third edition
https://github.com/CodeClub-JU/Introduction-to-Algorithms-CLRS/blob/master/Introduction%20to%20Algorithms%20-%203rd%20Edition.pdf

# Randomized QuickSort
The randomized version of quicksort is similair to quicksort, except that it adds randomization in order to obtain good expected performance over all inputs. Many regard this version of quicksort as the sorting algorithm of choice
for large enough inputs.
Instead of using A[r] as the pivot, we select a random pivot from the subarray A[p...r]

##Expected  Running time:
The expected running time is O(n lg n), where the recursion tree has a depth of \theta (lg n) with O(n) work at each level.

## References
Introduction to Algorithms, Third edition
https://github.com/CodeClub-JU/Introduction-to-Algorithms-CLRS/blob/master/Introduction%20to%20Algorithms%20-%203rd%20Edition.pdf

# Insertion Sort
The Insertion Sort algorithm works by comparing each element to each other element in the array. The best case running time for insertion sort occurs when the array is already sorted. A reverse sorted array results in the worst case.

## Expected  Running time:
The expected running time is O(n^2).

## Expected  Running time:
The expected running time is also O(n^2).

## References
Introduction to Algorithms, Third edition
https://github.com/CodeClub-JU/Introduction-to-Algorithms-CLRS/blob/master/Introduction%20to%20Algorithms%20-%203rd%20Edition.pdf

# Stack

Stack in first in last out algorithms (FILO) that any thing get in first then it will get to out side last when we want to add data to stack we need to append and when we want to get data we need to pop data from stack

[includehelp](https://www.includehelp.com/data-structure-tutorial/stack-using-c-and-cpp-data-structure-tutorial.aspx)

# Selection Sort
1. look for the min in current list [i=0..end]
2. if min out of place, swap
3. L[i] is in correct position so we repeat on sublist [i+1..end]

Reminders:
- must keep track of sublist we are searching through
- if you find min out of place, swap
- find min in current list
- after each iteration apply, list[i+1]
- sublist made after each minimum is added to correct spot
- go until last sublist has only two, so i is n[-1] or i is <= n-2

