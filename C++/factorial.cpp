#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
	int a = 1;
	while(n){
		a *= n--;
	}
	return a;
}

int main(){
	int n;
	cin >> n;
	cout << factorial(n) << endl;
	return 0;
}
