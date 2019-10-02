
//Bubble Sort
/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

 i->0                  n-1
    5  3  7  1  2  4    9
j->0             n-1-i 
*/

// O(n^2)
using System;

namespace sorting
{
    public class Program
    {
        public static void Main()
        {
            int [] arr = {2,3,1,5,4};
            bubbleSort(arr);
            Console.WriteLine("Sorted Array");
            PrintArray(arr);
        }
        static void PrintArray(int []arr){
            int n = arr.Length;
            for(int i=0;i<n;i++){
                Console.Write(arr[i]+" ");
            }
        }
        static void bubbleSort(int []arr){
            int n = arr.Length;
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(arr[j]>arr[j+1]){
                        int t = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = t;
                    }
                }
            }
        }
    }
}
