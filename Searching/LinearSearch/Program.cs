
//Linear search O(n)
//O(1) > O(logn)>O(n) > O(nlog)>O(n^2) > O(2^n)>O(n!)

using System;

namespace LinearSearch
{
    					
public class Program
{
	public static int search(int [] arr,int x){
		int n = arr.Length;
		
		for(int i=0;i<n;i++){
			if(arr[i] == x){
				return i;
			}
		}
		return -1;
	}
	public static void Main()
	{
		int[] arr = {1,2,3,4,5};
		Console.WriteLine("enter search element");
		string userinput =  Console.ReadLine();
		int user = Convert.ToInt32(userinput);
        
		int search_result = search(arr,user);
		if(search_result == -1)
			Console.WriteLine("Element is not present in array");
		else
			Console.WriteLine("Element is present at index " + search_result);
		
}
}
}
