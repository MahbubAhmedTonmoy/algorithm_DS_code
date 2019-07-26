

/*
abcda
bdabac

LCS=3 given by the subsequence "abc"


sbbksg
bpkpsjg

LCS=4 given by the subsequence "bksg"

classical
musical

LCS=5 given by subsequence "sical"


string1[i] == string[j]
   |
---|----
   |copy from diagonal dp[i-1][j-1] + 1

-------------------
string1[i] != string[j]
   |
---|----
   |(max of 3)

-----------------------
tabulation :
->string1|        null   a    b   c     d    a
    string2  null|_0_||_0_||_0_||_0_||_0_||_0_| common AbCdE string with null means 0
              b  |_0_||_0_||_1_||_1_||_1_||_1_|
              d  |_0_||___||___||___||___||___|
              a  |_0_||___||___||___||___||___|
              b  |_0_||___||___||___||___||___|
              a  |_0_||___||___||___||___||___|
              c  |_0_||___||___||___||___||___|

*/

#include<bits/stdc++.h>
using namespace std;

char A[200],B[200];
int dp[200][200];
/*
int max(int a,int b,int c)
{
    return max(max(a,b),c);
}*/

int Longest_common_subsequence(int s1,int s2)
{
    for(int i=0;i<=s1;i++)
    {
        for(int j=0;j<=s2;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;

            else if(A[i-1]==B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j],
                                 dp[i][j-1]);
            }
        }
    }
    return dp[s1][s2];
}

int main()
{
    printf("input two string \n");
    scanf("%s%s",&A,&B);
    printf("Longest common subsequence : %d",Longest_common_subsequence(strlen(A),strlen(B)));
}
