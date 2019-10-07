#include <stdio.h>
#include <math.h>

void swap(int* a, int* b);
int greater(int a, int b);
int lesser(int a, int b);

void insertion_sort(int* array, int lenght, int (*f)(int, int));
void print_array(int* array, int lenght);

#define V_MAX 1001 // Maximum vector lenght +1

int main(void) {
    int i, n = -1;
    int v[V_MAX];

    // Get the input lenght from user
    while (n < 0 || n >= V_MAX) {
        scanf("%d", &n);
    }

    // Read the n entries as requested
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    // Sort the array with a insertion sort
    insertion_sort(v, n, greater);

    // Print a line with the sorted numbers
    print_array(v, n);

        // Sort the array with a insertion sort
    insertion_sort(v, n, lesser);

    // Print a line with the sorted numbers
    print_array(v, n);
    
    return 0;
}

// Swaps two integers using pointers
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// A insertion sort algotithm that accepts an array of integers, 
//  it's lenght, and a function to set its swapping condition
void insertion_sort(int *array, int size, int (*f)(int, int)) {
	for(int i = 0; i < (size - 1); i++)
		for (int j = i + 1; j < size; j++)
			if ((*f)(array[i], array[j]))
				swap(&array[i], &array[j]);	
}

// A comparative function that returns 1 (true)
//  if a is greater than b and 0 (false) if otherwise
int greater(int a, int b) {
	return a > b;
}

int lesser(int a, int b) {
	return a < b;
}

// Prints all array elements in a single line
//  with proper spacing and end of line
void print_array(int* array, int lenght) {
    int i = 0;
    for (; i < lenght; i++) {
        printf("%d", array[i]);
        if (i < lenght - 1)
            printf(" ");
        else
            printf("\n");
    }
}
