/**
 * @param {Array} Array
 * @return {Array}
 */

export default function selectionSort(ar) {
    for (let i =0; i < ar.length; i++) {
        let min = i
        for (let j = i+ 1; j < ar.length; j++) {
            if (ar[j] < ar[min]) {
                min = j
            }
        }
        let temp = ar[i]
        ar[i] = ar[min]
        ar[min] = temp
    }
    return ar
}