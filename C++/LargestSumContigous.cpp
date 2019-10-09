#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n]; //you can use dynamic memory allocation as well!
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
} 
