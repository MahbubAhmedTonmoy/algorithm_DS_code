/*
time com : O(nlogn)
            worst case O(n^2)
 */
/*
implemention
call quixksort function (a,low,high)
call divide function
                          pivot
element     2 8 7 1 3 5 6 4
            _ _ _ _ _ _ _ _ 
index       0 1 2 3 4 5 6 7 
            lo            hi
1>      pivot = 4
        i = -1,j = 0
        2<= 4 ? i++ swap
2>      pivot = 4
        i = 0,j =1
        8<=4? no j++
3>      pivot = 4
        i = 0,j =2
        7<=4? no j++
4>>     pivot = 4
        i = 0,j =3
        1<=4? i++,swap
ele ment    2 1 7 8 3 5 6 4
            _ _ _ _ _ _ _ _ 
index       0 1 2 3 4 5 6 7 
            lo            hi
5>      pivot = 5
        i=1,j= 4 
        3<=4? i++,swap
ele ment    2 1 3 8 7 5 6 4
            _ _ _ _ _ _ _ _ 
index       0 1 2 3 4 5 6 7 
            lo            hi
6>      pivot = 4
        i = 2,j =5
        8<=4? no j++
7>      pivot = 4
        i = 2,j =6
        7<=4? no j++
last swap (i+1,high)=>(index 3, 7)
ele ment    2 1 3 4 7 5 6 8
            _ _ _ _ _ _ _ _ 
index       0 1 2 3 4 5 6 7 
            lo            hi
pass i+1 => index 3

dived :

                pivot            pivot
ele ment    2 1 3|   4    |7 5 6 8
            _ _ _|_       | _ _ _ 
index       0 1 2|        |4 5 6 7 
            lo  hi         lo     hi

again recursion call

 */


using System;

namespace QuickSort
{
    class Program
    {

        
        public static int devide(int [] a,int lo,int hi){

            int pivot = a[hi], i = lo-1;
            int t,s;

            for(int j=lo;j<hi;j++){
                if(a[j] <= pivot){
                    i++;
               // swap(a[i],a[j]);
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                }
            }
               // swap (a[i+1],a[hi]);
               
                s = a[i+1];
                a[i+1] = a[hi];
                a[hi] = s;
                return i+1;

        }
        public static void quicksort(int [] a, int low,int high){
            if(low<high){
                int p = devide(a,low,high);
                quicksort(a,low,p-1);
                quicksort(a,p+1,high);
            }
        }

    public static void printArray(int [] a,int n){
            for(int i=0;i<n;i++){
                Console.Write(a[i] + " ");
            }
            Console.WriteLine();
        }
        public static void Main()
        {
            int[] arr = {2,8,7,1,3,5,6,4};
            
            int n = arr.Length;
            Console.WriteLine("Before sort");
            printArray(arr,n);
            quicksort(arr,0,n-1);
            Console.WriteLine("After sort");
            printArray(arr,n);
        }
    }
}
