/*

same as 0/1 knapsack but difference is 1 item select multiple time

so update row value =value of item + dp[same row][column - weight of item]

item value weight
1      3    2
2      7    3
3      2    4
4      9    5
capacity= 5

2d array dp[item+1][capacity+1]

capacity  0    1    2    3    4    5
       0|_0_||_0_||_0_||_0_||_0_||_0_|
       1|_0_||_0_||_3_||_3_||_6_||_6_|
       2|_0_||_0_||_3_||_7_||_7_||10_|
       3|_0_||_0_||_3_||_7_||_7_||10_|
       4|_0_||_0_||_3_||_7_||_7_||10_|
      item

      for(i 0->item)
        for(j 0->capacity)
      weight of item < index of capacity(j)
          dp[i-1][j] // previous row value
    else
        max (previous row value, item value+dp[i][j-weight of item])


*/

#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a>b)? a:b;
}

void knapsack(int capacity,int wt[],int val[],int item)
{
    int i, j;
   int dp[item+1][capacity+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= item; i++)
   {
       for (j = 0; j <= capacity; j++)
       {
           if (i==0 || j==0)
               dp[i][j] = 0;

           else if (j < wt[i-1])
           {
               dp[i][j] = dp[i-1][j];
           }
           else{
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]],  dp[i-1][j]);

           }
       }
   }

   for(int i=0;i<=item;i++)
   {
       for(int j=0;j<=capacity;j++)
       {
           cout << dp[i][j]<<"    ";
       }
       cout << endl;
   }

   printf("%d\n", dp[item][capacity]);


}



int main()
{
    int n,W;
    cout << "Enter the number of items in a Knapsack:";
    cin >> n;
    int val[n],wt[n];
    cout << "Enter value items"<< ":";
    for(int i=0;i<n;i++)
    {

        cin >> val[i];
    }
    cout << "Enter weight items"  << ":";
     for(int i=0;i<n;i++)
    {

        cin >> wt[i];
    }
    cout << "Enter the capacity of knapsack : ";
    cin >> W;
    knapsack(W, wt, val, n);

    //printf("%d", knapsack(W, wt, val, n));
}
/*
5
4 9 32 23 19
1 2 7 5 4
14
*/
