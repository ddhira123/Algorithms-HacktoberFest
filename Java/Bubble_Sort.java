public class BubbleSort {

	public static void main(String[] args) {
		
		int arr[] = {2,7,5,1,8,3};
		
		for(int i=0;i<arr.length;i++){
			for(int j=i+1;j<arr.length;j++){
				if(arr[i]>arr[j]){
					swap(arr,i,j);
				}
			}
		}
		
		for(int i =0;i<arr.length;i++){
			System.out.println(arr[i]);
		}

	}

	public static void swap(int arr[],int i,int j){
		
		if(i==j){
			return;
		}
		int temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		
	}

}
