//an example of merge sort algorithm
function mergeSort(arr1, arr2) {
    let newArr = [];
    let i = 0;
    let j = 0;
    //loop through arrays until one is exhausted of elements
    while (i < arr1.length && j < arr2.length) {
        if (arr1[i] <= arr2[j]) {
            newArr.push(arr1[i]);
            i++;
        } else {
            newArr.push(arr2[j]);
            j++
        }
    }
    //loop through the elements of the remaining array
    if (i === arr1.length) {
        while (j !== arr2.length) {
            newArr.push(arr2[j]);
            j++;
        }
    } else {
        while (i !== arr1.length) {
            newArr.push(arr1[i])
            i++
        }
    }
    return newArr
}

function divideAndConquer(array) {
    //slice array elements until they have 1 element by dividing array in half
    //resulting in newArray - 1 half and newArrayTwo - the other half
    if (array.length > 1) {
        var index = Math.floor(array.length / 2);
        var newArray = array.slice(0, index);
        var newArrayTwo = array.slice(index, array.length);
        if (newArray.length > 1) {
            newArray = divideAndConquer(newArray);
        }
        if (newArrayTwo.length > 1) {
            newArrayTwo = divideAndConquer(newArrayTwo);
        }
    }
    return mergeSort(newArray, newArrayTwo);
}

var result = divideAndConquer([1, 2, 32, 4, 8, 9, 110, 6, 6, 7, 9, 8, 13]);
console.log(result);