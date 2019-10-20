#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Entre the number of elemnts";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //insertion sort starts here
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
    cout << "Sorted array is\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}