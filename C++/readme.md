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

N DIGIT FIBONACCI NUMBER: This function returns the number of digits in nth Fibonacci number after ceiling it

# Palindrome





```


1.First get the input for the string;


2.Initialise 1 variable with value 0 and another variable with value size-1 


3.Then put those variable in for loop and create a temprorary variable and give the value 0


4.check for the condition string[j]!=string[i]


5.If true update the value of temproray variable 


6.At last add the codition if temproray variable==0 then print output as palindrome





```
=======

# Palindrome

1.First get the input for the string;
2.Initialise 1 variable with value 0 and another variable with value size-1
3.Then put those variable in for loop and create a temprorary variable and give the value 0
4.check for the condition string[j]!=string[i]
5.If true update the value of temproray variable
6.At last add the codition if temproray variable==0 then print output as palindrome

=======

# 0/1 Knapsack problem
```
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
```
[Wikipedia](https://en.wikipedia.org/wiki/Knapsack_problem)
[GeeksForGeeks](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10)


=======

# Coin Change Problem
You are given with m coins of different denominations S = {S1, S2, ..., Sm}. You have infinite supply of each type of coin.
Your task is to find the number of ways in which a total of N cents be generated.

1.Input m
2.Input the array S.
3.Input N.
4.Take an array dp[m+1] and initialise it to 0
5.dp[0]=1
6.i=0
7.Repeat steps 8-12 till i<N
8.j=S[i]
9.Repeat steps 10-11 till j<=M
10.dp[j]=dp[j]+dp[j-S[i]]
11.j=j+1
12.i=i+1
13.Print dp[M]

=======

# Counting Sort
An integer sorting algorithm that is in O(n+k) complexity where k is the magnitude of the range of values to be sorted.