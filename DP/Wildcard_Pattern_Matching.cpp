
/*

dp[0][0] = true
dp[0][j] if ch[j] ==  * true
         else false

dp[i][0] all false

--------------------------
if ? or st[i] != st[j]
       |
    ---|---
       |same as [i-1][j-1]
--------------------------
if *    [i][j-1] || [i-1][j] which one is true

-----------------------------

example:
x*y?x
xayax
      null | x | * | y | ? | x
    -------|---|---|---|---|---
    null 1 | 0 | 1 | 0 | 0 | 0
    -------|---|---|---|---|----
    x    0 | 1 | 1 | 0 | 0 | 0
    -------|---|---|---|---|----
    a    0 | 0 | 1 | 0 | 0 | 0
    -------|---|---|---|---|----
    y    0 | 0 | 1 | 1 | 0 | 0
    -------|---|---|---|---|----
    a    0 | 0 | 1 | 0 | 1 | 0
    -------|---|---|---|---|----
    x    0 | 0 | 1 | 0 | 0 | 1




*/

#include<bits/stdc++.h>
using namespace std;

char patern[1000],input[10000];


int Wildcard_Pattern_Matching(int s,int p){

    int dp[s+1][p+1];

    dp[0][0] = 1;

   for(int j=1;j<=p;j++){
        if(patern[j-1]=='*'){
            dp[0][j] = 1;
        }
        else{
            dp[0][j] = 0;
        }
    }
    for(int i=1;i<=s;i++){

            dp[i][0] = 0;
    }
    for(int i=1;i<=s;i++){
        for(int j=1;j<=p;j++){

          // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move
            //    to next  character in the pattern,
            //     i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith
            //     character in input
             if(patern[j-1]=='*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if(patern[j-1]=='?' || input[i-1] == patern[j-1]){

                dp[i][j] = dp[i-1][j-1];
            }
             // If characters don't match
            else{
                dp[i][j] = 0;
            }
        }
    }

    for(int i=0;i<=s;i++){
        for(int j=0;j<=p;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[s][p];
}

int main(){

    cout <<"enter pattern like *aa? or some thing "<<endl;
    gets(patern);
    cout <<"enter input string "<<endl;
    gets(input);
    int n=strlen(input);
    int m = strlen(patern);
    //int a = strmatch(input,patern,n,m);
    int a = Wildcard_Pattern_Matching(n,m);
    if(a == 1){
        cout << "true"<<endl;
    }
    else{
        cout << "false"<<endl;
    }
}
