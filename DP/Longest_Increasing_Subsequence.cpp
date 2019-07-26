
/*


number [] = 10 9 2 3 7 101 18

10 = 1
9  = 1 1
2  = 1 1 1
3  = 1 1 1 2
7  = 1 1 1 2 3
101= 1 1 1 2 3 4
18 = 1 1 1 2 3 4 4
 return 4

           i j
 number = 10 9 2 3 7 101 18
 ans    = 1  1 1 1 1  1   1
 for j=1 to n-1
    for i=0 to i
    if(number[i] < number[j])
      set value -> ans[j] = max(ans[i], ans[j]+1)
*/





#include<bits/stdc++.h>
using namespace std;
int arr[100],n,el;

int max(int a,int b)
{
    return (a>b)? a:b;
}
int LIS()
{
    int lis[n];
    for(int i=0;i<n;i++) lis[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i]){
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }
    return *max_element(lis, lis+n);
}

int main()
{
    cout << "enter size : ";
    cin >> n;
    for(int i=0;i<n;i++){
            cin >> el;
        arr[i] = el;
    }
    cout << LIS();
}
