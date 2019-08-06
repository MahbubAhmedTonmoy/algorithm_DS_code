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
        print();
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
            else break ;
            p = ch ;
        }
    }
    void print()
    {
         cout <<"max heap :"<<endl;
        for(int i=1;i<=cnt;i++){
            cout << arr[i]<<" ";
        }
        cout << endl;
    }

    void sort_h(){
        int c = cnt;
        for(int i=1;i<c;){
            swap(&arr[i],&arr[c]);
            int p = i ;
        while(2*p<=c-1)
        {
            int ch = 2*p ;
            //cout << ch;
            if(ch+1<=c-1)
            {
                if(arr[ch+1]>arr[ch]) ch++;
            }
            if(arr[ch]>arr[p]) swap(&arr[p],&arr[ch]);
            else break ;
            p = ch ;
        }
        c--;

        }
         cout <<"sorted heap :"<<endl;
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
 void insert(int a)
    {
        arr[++cnt] = a ;
       //print();
        int ch = cnt ;
        while(ch/2>0)
        {
            if(arr[ch]<arr[ch/2]) swap(&arr[ch/2],&arr[ch]);
            else break ;
            ch/=2;
        }
    }
    void remove()
    {
        arr[1] = arr[cnt--] ;
        int p = 1 ;
        while(2*p<=cnt)
        {
            int ch = 2*p ;
            if(ch+1<=cnt)
            {
                if(arr[ch+1]<arr[ch]) ch++;
            }
            if(arr[ch]<arr[p]) swap(&arr[p],&arr[ch]);
            else break ;
            p = ch ;
        }
    }
    void print()
    {
        cout <<"min heap :"<<endl;
        for(int i=1;i<=cnt;i++){
            cout << arr[i]<<" ";
        }

    }
     void sort_h(){
        int c = cnt;
        for(int i=1;i<c;){
            swap(&arr[i],&arr[c]);
            int p = i ;
        while(2*p<=c-1)
        {
            int ch = 2*p ;
            //cout << ch;
            if(ch+1<=c-1)
            {
                if(arr[ch+1]<arr[ch]) ch++;
            }
            if(arr[ch]<arr[p]) swap(&arr[p],&arr[ch]);
            else break ;
            p = ch ;
        }
        c--;

        }
         cout <<"\nsorted heap :"<<endl;
        for(int i=1;i<=cnt;i++){
            cout << arr[i]<<" ";
        }
        cout << endl;
    }
};
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
   h.sort_h();
   h.remove();
   h.sort_h();

     MIN_heap h1;
    h1.insert(1);
     h1.insert(3);
      h1.insert(6);
       h1.insert(5);
        h1.insert(9);
        h1.print();
        h1.sort_h();
}
