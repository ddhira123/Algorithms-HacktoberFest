pragma solidity >=0.4.24 <0.6.0;

contract SortArray {

    struct Items {
        uint[] items;
    }

    function sort(uint[] storage items, bool desc) private returns (uint[] memory) {
        uint length = items.length;
        uint[] storage arr = items;

        for (uint i = 0; i < length; i++) {
            for (uint j = i + 1; j < length; j++) {
                bool condition;
                if (desc) {
                    condition = arr[i] < arr[j];
                } else {
                    condition = arr[i] > arr[j];
                }
                if (condition) {
                    uint temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }   
        }
        return arr;
    }
}