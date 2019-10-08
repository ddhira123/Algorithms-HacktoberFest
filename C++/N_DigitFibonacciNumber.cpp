/*What is the first term in the Fibonacci sequence to contain N digits? */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// This function returns the number of digits
// in nth Fibonacci number after ceiling it
// Formula used (n * log(phi) - (log 5) / 2)
long long numberOfDigits(long long n)
{
    if (n == 1)
        return 1;

    // using phi = 1.6180339887498948
    long double d = (n * log10(1.6180339887498948)) -
                    ((log10(5)) / 2);

    return ceil(d);
}


int main() {
	int N = 4; //example output = 17
	bool found = false;

	int j = 0;
	while (!found){
		j++;
		int p = numberOfDigits(j);
		//cout << p << " _ " << j <<endl;
		found = p >= N;
	}
	cout << j <<endl;
	return 0;
}
