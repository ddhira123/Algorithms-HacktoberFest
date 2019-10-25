package Lecture9;

import java.util.Scanner;

public class MergeSort {

	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = takeinput();
		int rv[] = mergesort(arr, 0, arr.length - 1);
		display(rv);
	}

	public static int[] takeinput() {
		System.out.println("enter size of array");
		int N = scn.nextInt();
		int rv[] = new int[N];
		for (int i = 0; i < N; i++) {
			rv[i] = scn.nextInt();
		}

		return rv;
	}

	public static void display(int[] arr) {

		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static int[] merge2sortedarrays(int[] one, int[] two) {
		int array[] = new int[one.length + two.length];
		int a = 0;
		int b = 0;
		int i = 0;
		while (a < one.length && b < two.length) {
			if (one[a] < two[b]) {
				array[i] = one[a];
				i++;
				a++;
			} else {
				array[i] = two[b];
				i++;
				b++;
			}
		}
		while (a < one.length) {
			array[i] = one[a];
			i++;
			a++;
		}
		while (b < two.length) {
			array[i] = two[b];
			i++;
			b++;
		}
		return array;
	}

	public static int[] mergesort(int[] arr, int si, int li) {
		if (si == li) {
			int[] baseresult=new int[1];
			baseresult[0]=arr[si];
			return baseresult;
		}
		
		int mid = (si + li) / 2;
		int[] fhalf = mergesort(arr, si, mid);
		int[] shalf = mergesort(arr, mid + 1, li);
		int[] sortedarr = merge2sortedarrays(fhalf, shalf);
		return sortedarr;
	}
}
