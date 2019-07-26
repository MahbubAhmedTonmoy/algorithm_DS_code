/*

string1 :
string2 :

char add/delete/change (+1) cost


string1[i] == string[j]
   |
---|----
   |copy from diagonal dp[i-1][j-1]

-------------------
string1[i] != string[j]
   |
---|----
   |(min of 3) + 1

-----------------------
tabulation :
->string1|   null   A    b   C     d    E
------------------------------------------
string2  null|_0_||_1_||_2_||_3_||_4_||_5_| exchange AbCdE string with null string perform 1 operation
          a  |_1_||_1_||_2_||_3_||_4_||_5_|
          B  |_2_||___||___||___||___||___|
          c  |_3_||___||___||___||___||___|
          d  |_4_||___||___||___||___||___|


*/



#include<bits/stdc++.h>
using namespace std;

char A[200],B[200];
int dp[200][200];

int min(int a,int b,int c)
{
    return min(min(a,b),c);
}

//tabulation
int edit_distance(int lengthA,int lengthB)
{
   // for(int i=1;i<lengthA;i++) dp[i][0]=i;
   // for(int i=1;i<lengthB;i++) dp[0][i]=i;
    for(int i=0;i<=lengthA;i++)
    {
        for(int j=0;j<=lengthB;j++)
        {
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(dp[i-1][j],
                                 dp[i-1][j-1],
                                 dp[i][j-1]);
            }
        }
    }
    return dp[lengthA][lengthB];
}
int main()
{
    scanf("%s%s",&A,&B);
    printf("minimum edit distance : %d",edit_distance(strlen(A),strlen(B)));
}
