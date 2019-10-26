<?php
/* Binary Search implementation in PHP */
function binarySearch(Array $arr, $item) {
    $low = 0;
    $high = count($arr) - 1;
	$found = false;
	while ($low <= $high) {
		$mid = $low + ($high - $low) / 2; //Midpoint of the Search Space
		if ($arr[$mid] === $item) { //Found the element
			$found = true;
			break;
		} else {
			if ($item < $arr[$mid]) { 
				$high = $mid - 1;
			} else { 
				$low = $mid + 1;
			}
		}
	}
	return $found;
}
?>
