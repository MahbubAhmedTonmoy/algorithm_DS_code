

/*
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=0, index2=1



method
step 1: sort array
step 2: i=0;j=length-1
        sum = a[i]+a[j]
        if(sum > target) means our j is big so j--
        else if(sum < target) means our i is smaller i++
        else print ans;
*/
#include <bits/stdc++.h>
using namespace std;


int number[10000];
int target,n;

void sum2()
{
    int i=0;
    int j= n-1;
    while(i<j)
    {

        if(number[i]+number[j] == target)
        {
             printf("%d + %d = %d\n",number[i],number[j],target);
             i++,j--;
        }
        else if(number[i]+number[j] < target)
        {
            i++;
        }
        else{
           j--;
        }
    }
}

int main()
{
    cout << "enter array size"<<endl;
    cin >> n;
    cout << "enter numbers "<<endl;
    for(int i=0;i<n;i++){
        cin >> number[i];
    }
    sort(number,number+n);
    cout << "enter target value "<<endl;
    cin >> target;
    //int l = sizeof(number)/sizeof(number[0]);
    sum2();
return 0;
}
