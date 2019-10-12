public class Bubble_Sort {

	public static void main(String[] args) {

		int arr[] = {2,7,5,1,8,3};
		boolean swapped;
		int temp;

		for(int i=0;i<arr.length-1;i++){

			swapped=false;

			for(int j=0;j<arr.length-i-1;j++){

				if(arr[j]>arr[j+1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
					swapped =true;
				}

			}
			if(swapped==false)
			break;
		}

		for(int i =0;i<arr.length;i++){
			System.out.println(arr[i]);
		}

	}

}
