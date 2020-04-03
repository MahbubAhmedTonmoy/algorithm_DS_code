#include<bits/stdc++.h>
using namespace std;

void coinChange(int coin[],int coinsize, int ammount)
{

    int i,j, x, y;
    int dp[coinsize+1][ammount+1];

      for(int i=0;i<=coinsize;i++){
        for(int j=0;j<=ammount;j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i==0 && j!=0) dp[i][j] = 0;
                else if(coin[i-1]> j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j]+ dp[i][j-coin[i-1]];

            }
            cout << endl;
        }

        cout << "ans : " <<dp[coinsize][ammount]<< endl;
        cout<< "table" <<endl;

     for(int i=0;i<=coinsize;i++){
        for(int j=0;j<=ammount;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }


}
int main()
{
    int n,ammount;
    cout << "Enter the number of coins :";
    cin >> n;
    int coin[n];
    cout << "Enter value of coins"<< ":";
    for(int i=0;i<n;i++)
    {

        cin >> coin[i];
    }

    cout << "Enter the total ammount : ";
    cin >> ammount;

    coinChange(coin, n,ammount);
}
