// Binary search O(logn) if sorted

// unsorted array O(nlogn+logn)

/*
 L     M       R
 0 1 2 3 4 5 6 7
 - - - - - - - - 
 mid = (0 + 7)/2 = 3.5 = 3

 if search element == arr[mid] => result mid
 -----------------------------------------------
 if(search element > arr[mid]) element found in right of mid of update left = mid + 1
         L     R
 0 1 2 3 4 5 6 7
 - - - - - - - - 
 -----------------------------------------------------------
 if(search element < arr[mid]) element found in left of mid of update right = mid -1
 L   R         
 0 1 2 3 4 5 6 7
 - - - - - - - - 
 ----------------------------------------------------------------
 */
using System;

namespace BinarySearch
{
    public class Program
    {

        public static int Binarysearch(int []arr,int left,int right ,int x){
        if(right>=left){
        int mid = (left+right)/2;
        
        if(x == arr[mid])
        {
            return mid; // index no return
        }
        if(x> arr[mid]){
            return Binarysearch(arr, mid+1,right , x);
        }
        else{
           return Binarysearch(arr, left,mid-1 , x);
        }
        }
        return -1;
    }
    public static void Main()
	{
		int[] arr = {1,2,3,4,5,10};
		Console.WriteLine("enter search element");
		string userinput =  Console.ReadLine();
		int user = Convert.ToInt32(userinput);
		
        int n = arr.Length;

		int search_result = Binarysearch(arr,0,n-1,user);
		if(search_result == -1)
			Console.WriteLine("Element is not present in array");
		else
			Console.WriteLine("Element is present at index " + search_result);
    }
    }
    
}