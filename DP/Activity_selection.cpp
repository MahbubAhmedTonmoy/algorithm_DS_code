
#include<bits/stdc++.h>
using namespace std;

struct Activitiy
{
    int job, start, finish;
}arr[10000];

bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

void printMaxActivities(Activitiy arr[], int n)
{

    sort(arr, arr+n, activityCompare);
    for(int i=0;i<n;i++)
    {

        cout <<arr[i].job<<" "<< arr[i].start <<" "<<  arr[i].finish << endl;
    }

    cout << "Following activities are selected ";

    int i = 0;
    //cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
cout << "\nActivity: " << arr[i].job << " , Start: " <<arr[i].start << " End:" << arr[i].finish <<endl;


    for (int j = 1; j < n; j++)
    {

      if (arr[j].start >= arr[i].finish)
      {
         // cout << "(" << arr[j].start << ", "<< arr[j].finish << "), ";


  cout << "Activity: " << arr[j].job << " , Start: " <<arr[j].start << " End:" << arr[j].finish <<endl;


          i = j;
      }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        arr[i].job = i+1;
        cin >> arr[i].start >> arr[i].finish;
    }
    //Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    printMaxActivities(arr,n);
}
/*
6
5 9
1 2
3 4
0 6
5 7
8 9
*/

