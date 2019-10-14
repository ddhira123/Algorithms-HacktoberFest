/**
 * 
 * @param {*} arr 
 * Bubble Sort: Sorts the array in ascending order
 * Time Complexity: O(N^2)
 */
export default function bubbleSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    for (let j = i; j < arr.length; j++) {
      if (arr[i] > arr[j]) {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  return arr;
}