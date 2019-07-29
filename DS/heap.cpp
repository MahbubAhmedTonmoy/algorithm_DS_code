/*


insert::

1 3 6 5 9
1 ch = 1;
1st step: 1
2nd step
ch = 2 (2/2 = 1)
so (arr[ch]>arr[ch/2) swap
   1       3
  /   - >> /
  3        1

3rd step 1 3 6
    3
    /\
    1 6
ch = 3/2 = 1 (arr[ch]>a[ch/2]) swap
 so     6
        /\
        1 3
------------------------------------

remove::
9 6 3 1 5
5 6 3 1 remove root 9
p = 1
ch = 2*p

decide which side we go ch / ch+1 ---> if(ch+1 > ch ) ch++   then if(arr[ch]> arr[p))swap [p][ch]
            5 (1)-p
            /\
 (2)ch     6 3 (3)ch+1
          /
          1
*/



#include <bits/stdc++.h>
using namespace std;

class MAX_heap
{
    public:
    int cnt, arr[10000];
    public:
    heap()
    {
        cnt =0;
    }
    int size()
    {
        return cnt;
    }
    void swap(int *a,int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }


    void insert(int a)
    {
        arr[++cnt] = a ;
        //print();
        int ch = cnt ;
        while(ch/2>0)
        {
            if(arr[ch]>arr[ch/2]) swap(&arr[ch/2],&arr[ch]);
            else break ;
            ch/=2;
        }
    }


    void remove()
    {
        arr[1] = arr[cnt--] ;
        //print();
        int p = 1 ;
        while(2*p<=cnt)
        {
            int ch = 2*p ;
            //cout << ch;
            if(ch+1<=cnt)
            {
                if(arr[ch+1]>arr[ch]) ch++;
            }
            if(arr[ch]>arr[p]) swap(&arr[p],&arr[ch]);
            else break ; /// as it is max heap so max value already in root/top
            p = ch ;
        }
    }

    void print()
    {
        for(int i=1;i<=cnt;i++){
            cout << arr[i]<<" ";
        }
        cout << endl;
    }
};

class MIN_heap
{
    int cnt, arr[10000];
    public:
    heap()
    {
        cnt =0;
    }
    int size()
    {
        return cnt;
    }
    void swap(int *a,int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }


    void print()
    {
        for(int i=1;i<=cnt;i++){
            cout << arr[i]<<" ";
        }

    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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
    MAX_heap h;
    h.insert(3);
    h.insert(4);
    h.insert(7);
    h.insert(9);
    h.insert(1);
    h.insert(5);
    h.print();
    h.remove();
    h.print();
    h.insert(10);
    h.print();
    cout << "array : "<<endl;
    int array[100];
    int c=0;
    for(int i=1;i<=h.size();i++)
    {
        array[c++] = h.arr[i];
    }
    for(int i=0;i<c;i++)
    {
        cout << array[i] <<" ";
    }
    heapSort(array,c);
    cout << endl;
    printArray(array,c);
    /* MIN_heap h1;
    h1.insert(1);
     h1.insert(3);
      h1.insert(6);
       h1.insert(5);
        h1.insert(9);
        h1.print();*/
}
