/* 	
	compiles with:
 	gcc --std=c11 fibonacci_recursive.c -o fibonacci_recursive
 */
#include<stdio.h>

int fibonacci(int value)
{
	if (value == 0 || value == 1)
		return 1;
	else
		return ( fibonacci(value-2) + fibonacci(value-1));
} 
 
int main()
{
	int counter;

	printf("How many Fibonacci series?\n");
	scanf("%d", &counter);
 
	printf("Results:\n");
 	
 	int i;
	for (i = 1; i <= counter; i++)
	{
		printf("%d\n", fibonacci(i));
	}
 
	return 0;
}
 
