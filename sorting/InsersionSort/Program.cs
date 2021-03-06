﻿
//O(n^2)

/*Insertion sort is a simple sorting algorithm 
that works the way we sort playing cards in our hands. 

 	    i->0                    <|n
		2   3   1    5    4
            j->i go to o j--

*/
using System;

namespace InsersionSort
{
    class Program
    {
    public static void Main()
	{
		int [] arr = {2,3,1,5,4};
		insertionSort(arr);
		Console.WriteLine("Sorted Array");
		PrintArray(arr);
	}
	static void PrintArray(int []arr){
		int n = arr.Length;
		for(int i=0;i<n;i++){
			Console.Write(arr[i]+" ");
		}
	}
	static void insertionSort(int []arr){
		int n = arr.Length;
		for(int i=0;i<n;i++){
			for(int j=i;j>0;j--){
				if(arr[j]<arr[j-1]){
					int t = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = t;
				}
			}
		}
	}
        
    }
}
