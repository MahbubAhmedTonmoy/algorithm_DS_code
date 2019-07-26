/*

item value weight
1      3    2
2      7    3
3      2    4
4      9    5
capacity= 5

2d array dp[item+1][capacity+1]

capacity  0    1    2    3    4    5
       0|_0_||_0_||_0_||_0_||_0_||_0_|
       1|_0_||_0_||_3_||_3_||_3_||_3_|
       2|_0_||_-_||_3_||_7_||_7_||10_|
       3|_0_||_0_||_3_||_7_||_7_||10_|
       4|_0_||_0_||_3_||_7_||_7_||10_|
      item

      for(i 0->item)
        for(j 0->capacity)
      weight of item < index of capacity(j)
          dp[i-1][j] // previous row value
    else
        max (previous row value, item value+dp[i-1][j-weight of item])


find item
1st item last index of 2d array
select = dp[item][capacity];
if dp[i][j]== dp[i-1][j] go dp[i-1][j]
else weight = weight - weight of selected item
     next select = select - value of this item

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
   int K[item+1][capacity+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= item; i++)
   {
       for (j = 0; j <= capacity; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;

           else if (j < wt[i-1])
           {
               K[i][j] = K[i-1][j];
           }
           else{
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);

           }
       }
   }

   printf("%d\n", K[item][capacity]);

   int selected = K[item][capacity];
   int w = capacity;
   for(int i=item;i>0 && selected>0;i--)
   {

       if(selected == K[i-1][w]) continue;
       else{
        printf("item no %d - weight is %d\n ",i,wt[i-1]);
        selected = selected - val[i-1];
        w = w-wt[i-1];

       }
   }

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
void knapsack(int W,int wt[],int val[],int n)
{
    int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   printf("%d", K[n][W]);

   int item = K[n][W];
   w = W;
   for(int i=n;i>0 && item>0;i--)
   {

       if(item == K[i-1][w]) continue;
       else{
        printf("item no %d - weight is %d ",i,wt[i-1]);
        item = item - val[i-1];
        w = w-wt[i-1];

       }
   }
}


*/
//4 100 20 60 40 3 2 4 1 5







