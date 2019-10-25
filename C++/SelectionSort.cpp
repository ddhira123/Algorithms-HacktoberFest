#include <iostream>

using namespace std;


void selectionSort(int[], int);
void swap(int &, int &);

int main()
{
    const int SIZE = 6;

    int values[SIZE] = {8,3,5,7,1,2};

    cout << "The unsorted values are:" << endl;
    for(auto element : values)
        cout << element << " ";
    cout << endl;

    selectionSort(values, SIZE);

    cout << "The sorted values: " << endl;
    for(auto element : values)
        cout << element << " ";
    cout << endl;

    return 0;
}

void selectionSort(int array[], int size)
{
    int minIndex,
            minValue;

    for(int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for(int index = start + 1; index < size; index++)
        {
            if(array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


