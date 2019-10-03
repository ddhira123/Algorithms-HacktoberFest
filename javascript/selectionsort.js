// array to sort
var array = [90, 21, 52, 60, 45, 30, 17, 10, 15, 18];

// swap function helper
function swap(array, i, j) {
  var temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

function selectionSort(array) {
  for(var i = 0; i < array.length; i++) {
    var min = i;
    for(var j = i + 1; j < array.length; j++) {
      if(array[j] < array[min]) {
        min = j;
      }
    }
    if(i !== min) {
      swap(array, i, min);
    }
  }
  return array;
}

console.log(selectionSort(array)); 