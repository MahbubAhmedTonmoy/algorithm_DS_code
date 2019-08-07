

/*
abcxabcdabcdabcy
abcdabcyb


AbtxAabraabbabctabababy
abababy


*/

#include<bits/stdc++.h>
using namespace std;


int pattern_index[1000];

void pttern_index(char pattern[])
{
    int n = strlen(pattern);
    pattern_index[0] = 0;

    int j=0;
    for(int i=1;i<n;){
        if(pattern[i] == pattern[j])
        {
            pattern_index[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = pattern_index[j-1];
            }
            else{
                pattern_index[i] = 0;
                i++;
            }
        }
    }
     for(int i=0;i<n;i++){
        cout << pattern_index[i]<<" ";
    }
}
int stlstl_KMP(char text[],char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    int solution_index[n];
    int j=0;
    int i=0;
    for(;i<n && j<m;)
    {

        if(text[i] == pattern[j])
        {
            solution_index[i] = j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j = pattern_index[j-1];

            }
            else{
                solution_index[i] = 0;
                i++;

            }
        }

    }
    for(int i=0;i<n;i++){
        cout << solution_index[i]<<" ";
    }
    if(j==m)
    {
        cout <<"\n\nyes you input pattern is a substring of real text\n\n" << endl;
    }
    else
    {
        cout << "\n\nno match found\n\n"<<endl;
    }
}
int main()
{
    char text[10000],pattern[1000];
    cout <<"enter a text : ";
    gets(text);
    cout <<"\nenter a pattern you want to match : ";
    gets(pattern);
    cout <<"pattern prefix suffix value "<< endl;
    pttern_index(pattern);
    cout << endl;
    cout<<"text value "<<endl;
    stlstl_KMP(text,pattern);

}

