<?php
/*
Quicksort Algorithm is based on partitioning of array of data into smaller arrays.
And select the Highest index value as a Pivot element. Take two variables to point 
left and right of the list excluding pivot.Left points to the lower index than pivot element.
Right points are higher than Pivot element.while value at left is less than pivot element 
move right else move left.
*/
 
function quicksort($array) {
        if (count($array) == 0)
            return array();
 
        $pivot_element = $array[0];
        $left_element = $right_element = array();
 
        for ($i = 1; $i < count($array); $i++) {
            if ($array[$i] <$pivot_element)
                $left_element[] = $array[$i];
            else
                $right_element[] = $array[$i];
        }
 
        return array_merge(quicksort($left_element), array($pivot_element), quicksort($right_element));
}

$unsorted_numbers = array(3,7,1,26,43,12,6,21,23,73);
$sorted_numbers = quicksort($unsorted_numbers);
 
print_r($sorted_numbers);