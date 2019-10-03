// HEAP SORT
// To use this, call heap_sort() with a unsorted int*. Make sure ANT equals the size
// of this array. 

const int ANT = 8; 


void swap(int *arr, int r1, int r2) {
  int t = arr[r1];
  arr[r1] = arr[r2];
  arr[r2] = t;
}

void heapify(int *arr, int ant, int i) {
  int largest = i;

  // Find the children of this root
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= ant && arr[left] > arr[largest])
    largest = left;

  if (right <= ant && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(arr, i, largest);
    heapify(arr, ant, largest);
  }
}

void heap_sort(int *arr) {
  for (int i = ANT / 2; i >= 1; i--) {
    heapify(arr, ANT, i);
  }

  for (int i = ANT; i >= 1; i--) {
    swap(arr, 1, i);
    heapify(arr, i - 1, 1);
  }
}