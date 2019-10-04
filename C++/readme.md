# interpolation_search

```
Interpolation search is an improved variant of binary search. This search algorithm works on the probing position of the required value. For this algorithm to work properly, the data collection should be in a sorted form and equally distributed.

Binary search has a huge advantage of time complexity over linear search. Linear search has worst-case complexity of Ο(n) whereas binary search has Ο(log n).
```

```
Algorithm
Rest of the Interpolation algorithm is the same except the above partition logic.

Step1: In a loop, calculate the value of “pos” using the probe position formula.
Step2: If it is a match, return the index of the item, and exit.
Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.
Step4: Repeat until a match is found or the sub-array reduces to zero.
```

[Wikipedia](https://en.wikipedia.org/wiki/Interpolation_search)

# Binary Search:

```
Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
```

```
Algorithm

We basically ignore half of the elements just after one comparison.

1.Compare x with the middle element.
2.If x matches with middle element, we return the mid index.
3.Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
4.Else (x is smaller) recur for the left half.

```

[Wikipedia](https://en.wikipedia.org/wiki/Binary_search_algorithm)

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

[Wikipedia](https://en.wikipedia.org/wiki/Factorial)
