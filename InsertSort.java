/*
  An sorting algorithm which moves elements one at a time into the correct position.
  The algorithm consists of inserting one element at a time into the previously sorted part of the array, 
  moving higher ranked elements up as necessary. 
  To start off, the first (or smallest, or any arbitrary) element of the unsorted array is considered to be the sorted part.
*/
public class InsertSort {  
  
  
  public static void insertSort(int[] A){
  for(int i = 1; i < A.length; i++){
    int value = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > value){
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = value;
  }
}


}




