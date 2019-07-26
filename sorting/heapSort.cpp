
/*

given array = 5 3 17 10 84 19 6 22 9

             5(0)
            / \
        (1)3   17(2)
          / \  / \
      (3)10  84 19 6(6)
        / \
       22  9(8)
 after sorted 84 22 10 19 17 6 5 9 3

 step:
 5 3 17 10 84 19 6 22 9 -> n=9
 n/2-1= 4-1 = 3->10| l->22| r->9| l(22)>i(10) swap (22,10)
 5 3 17 22 84 19 6 10 9

*/

#include<bits/stdc++.h>

using namespace std;
int arr[1000],n,e;

void MAX_heapify(int arr[],int n,int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int large = i;
    if(l<n && arr[l]>arr[large])
        large = l;
    if(r<n && arr[r]>arr[large])
        large = r;
    if(large != i)
    {
        swap(arr[i],arr[large]);
        MAX_heapify(arr,n,large);
    }
}



void heapSort(int arr[],int n)
{
     for (int i = n / 2 - 1; i >= 0; i--)
        MAX_heapify(arr,n,i);
     for (int i=n-1; i>=0; i--)
    {
        swap(arr[i],arr[0]);
        MAX_heapify(arr,i,0);
    }
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    cout<<"enter size of array : "<<endl;
    cin>>n;
    cout<<"enter array element "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> e;
        arr[i] = e;
    }
    cout << "sorted array : ";
    heapSort(arr,n);
    printArray(arr,n);
}
