
//Interpolation Search 
/*
 elements are uniformly distributed & sorted

 checks different location based on the element being searched  
 */
// O(loglogn)
// worst case O(n)

using System;

namespace Interpolation_Search
{
     public class Program
    {

        public static int Binarysearch(int []arr,int left,int right ,int x){
        if(right>=left && x <= arr[right] && x>=arr[left])
        {
            int mid = (left+ (((right-left)/(arr[right]-arr[left]))*(x-arr[left])));
            
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
		int[] arr = {1,2,3,4,5,6,7,10};
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
