<?php
  function insertionsort($array) {
    for ($i = 0; $i < count($array); $i++) {
      $val = $array[$i];
      $j = $i - 1;
      while($j >= 0 && $array[$j] > $val){
        $array[$j+1] = $array[$j];
        $j--;
      }
      $array[$j + 1] = $val;
    }
    return $array;
  }