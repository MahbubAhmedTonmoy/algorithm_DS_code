
/**
use greedy method when difference between coin >=2X (1,2,4,8,20,40)
amount = 27
coin = 5
coin value = 1 2 5 10 50
sort : 50 10 5 2 1

amount | coin opted | updated amount
  27   |   10       | 27-10 = 17
  17   |   10       | 17-10 = 7
  7    |    5       | 7-5 = 2
  2    |    2       | 2-2 = 0
**/

#include<bits/stdc++.h>
using namespace std;
void min_coins(int coin_value[],int n,int amount){

    for(int i=0;i<n;i++){
        while(amount>=coin_value[i]){
            amount = amount - coin_value[i];
            printf("%d ",coin_value[i]);
        }
    }
    printf("\n");
}
/* use for C
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a ); //for decreasing order
}
*/
int main(){
    int i,j,n,amount;
  printf( "Enter amount to be paid: ");
  scanf( "%d",&amount);
  printf( "Enter total kinds of currency: ");
  scanf("%d",&n);
  int coin_value[n]; //stores coins' values as per the user
  printf( "Enter all currency values: ");
  for(i = 0;i< n; i++)//
    scanf("%d",&coin_value[i]);
  //qsort(coin_value, n, sizeof(int), cmpfunc); //qsort is a built in funcition in C
  sort(coin_value,coin_value+n,greater< int>());
  printf( "The selected currecy values are: \n");
  min_coins(coin_value,n,amount);
  return 0;
}
