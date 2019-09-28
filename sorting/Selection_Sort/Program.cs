// selection sort O(n^2)

/* 

3|4|1|2|6|
----------
use 2 loop 
1st loop (0 - > n-1)
suppose min element is 1st value of Array

then compare with oder value using loop (i+1 -> n) if selected min is greater then compare then swap 2 value

*/


using System;

namespace Selection_Sort
{
		
public class Program
{
	public static void Main()
	{
		int [] arr = {2,3,1,5,4};
		selectionSort(arr);
		Console.WriteLine("Sorted Array");
		PrintArray(arr);
	}
	static void PrintArray(int []arr){
		int n = arr.Length;
		for(int i=0;i<n;i++){
			Console.Write(arr[i]+" ");
		}
	}
	static void selectionSort(int []arr){
		int n = arr.Length;
		for(int i=0;i<n-1;i++){
			int min = i;
			for(int j=i+1;j<n;j++){
				if(arr[j]<arr[min]){
					min = j;
				}
					
				}
				    int t = arr[i];
					arr[i] = arr[min];
					arr[min] = t;
			}
		}
	}
}

