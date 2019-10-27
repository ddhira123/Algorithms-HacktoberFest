/**
 * @param {*} arr
 * 
 * Counting Sort: Sorts the array in ascending order
 * by counting.
 * 
 * Time Complexity: O(MAX - MIN + n), where MAX and MIN
 * are the maximum and minimum of the array, respectively
 * and n is the length of the array.
 */

export default function countingSort(arr) {
  const len = arr.length;
  const MIN = Math.min(...arr);
  const MAX = Math.max(...arr);
  let count = [];

  for (let i = MIN; i <= MAX; i++) count[i] = 0;

  for (let i = 0; i < len; i++) count[arr[i]]++;

  let j = 0;
  for (let i = MIN; i <= MAX; i++)
    while (count[i]) {
      arr[j++] = i;
      count[i]--;
    }

  return arr;
}
