/*

6
number[] = {3 34 4 12 5 2}
sum = 9

dp[n+1][sum+1]

    0  1  2  3   4 5  6  7  8  9
--------------------------------
0 | 1  0  0  0  0  0  0  0  0  0
3 | 1  0  0  1  0  0  0  0  0  0
34| 1  0  0  1  0  0  0  0  0  0
4 | 1  0  0  1  1  0  0  1  0  0
12| 1  0  0  1  1  0  0  1  0  0
5 | 1  0  0  1  1  1  0  1  1  1
2 | 1  0  1  1  1  1  1  1  1  1

--------------------------------
1(true)

*/



#include<bits/stdc++.h>
using namespace std;

int sum,number[1000],dp[1000][1000],n;

void sub_set_sum()
{
    dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 && j==0) dp[i][j]=1;  /// using number empty array  make sum = 0 is possible so true
            if(i==0) dp[i][j]=0;  /// using number empty array  make sum = 1/2/3/4/5 or something is not possible false
            if(j==0) dp[i][j]=1; /// using number array [1,2,3,4,5] sum = 0 is true;
            else if(j<number[i-1])
            {
                dp[i][j] = dp[i-1][j]; ///sum is less then number copy from [previous row][same column]
            }
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-number[i-1]]; /// go to [previous row][sum-number]
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout << dp[i][j] <<"  ";
        }
        cout << endl;
    }
    printf("\nans 1 - means true\n0 - means false\n ans = %d ",dp[n][sum]);

}

int main()
{
    cout << "enter size of number array :";
    cin >> n;
    cout <<"enter numbers ";
    for(int i=0;i<n;i++)
    {
        cin >> number[i];
    }
    cout <<"enter sum :";
    cin >> sum;
    sub_set_sum();

}
