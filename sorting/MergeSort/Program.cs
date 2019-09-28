/*
time com : T(n){
                t(n/2)
                t(n/2)
                merge(t/2+t/2)
            }
t(n) = T(n/2)+T(n/2)+merge(n/2+n/2)
     = T(n/2)+T(n/2)+ n
     = 2T(n/2)+n
O(nlogn)

 */
/*
 0  1   2  3  4  5  6  7  8  9
 -- -- -- -- -- -- -- -- -- --
 recursive base case (n<2) return
 mid = 10/2 = 5;
 create 2 array left[mid] right[n-mid]
 left = [0 1 2 3 4] => left [0 1] => left [0] [1]
 right = [5 6 7 8 9]


 */



using System;

namespace MergeSort
{
    public class Program
    {
	    static void merge(int []a,int[] l,int[] r,int left,int right){
	    int i=0,j=0,k = 0;
			   
        while(i<left && j<right){
            if(l[i] <= r[j]){
			a[k++] = l[i++];
            }
            else{
                a[k++] = r[j++];
                }
		}
		while(i<left)
		{
			a[k++] = l[i++];
		}
			   
		while(i<right)
		{
			a[k++] = r[j++];
		}
			   
			   
	}
            
    static void mergesort(int [] a,int n){
        if(n<2){
            return;
        }
        int mid = n/2;
        int [] l = new int [mid];
        int [] r = new int [n-mid];
        
        for(int i=0;i<mid;i++){
            l[i] = a[i];
        }
        for(int i=mid;i<n;i++){
            r[i-mid] = a[i];
        }
        mergesort(l,mid);
        mergesort(r,n-mid);
        merge(a,l,r,mid,n-mid);
    }

	public static void printArray(int [] a,int n){
		for(int i=0;i<n;i++){
			Console.Write(a[i] + " ");
		}
        Console.WriteLine();
	}
    public static void Main()
	{
		int[] arr = {5,20,1,4,15,6,7,11};
		
        int n = arr.Length;
		Console.WriteLine("Before sort");
		printArray(arr,n);
		mergesort(arr,n);
		Console.WriteLine("After sort");
		printArray(arr,n);
	}
}
    

}
