
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int array[1000];

void merge_a(int a[],int l[],int r[],int n1,int n2)
{
    int i=0,j=0,k=0;

    printf("%d %d \n",n1,n2);
    while(i<n1 && j<n2)
    {

        if(l[i] <= r[j])
        {
            a[k++] = l[i++];
        }
        else{
            a[k++] = r[j++];
        }

    }
    // Store remaining elements of first array
    while (i < n1)
        a[k++] = l[i++];

    // Store remaining elements of second array
    while (j < n2)
        a[k++] = r[j++];
}
void mergesort(int a[],int n)
{

    if(n<2)return;

    int mid = n/2;
    int l[mid];
    int r[n-mid];

    for(int i=0;i<mid;i++){
        l[i] = a[i];
    }
    for(int i=mid;i<n;i++){
        r[i-mid] = a[i];
    }
    mergesort(l,mid);
    mergesort(r,n-mid);
    merge_a(a,l,r,mid,n-mid);
}
int main()
{
    int n,i;

    printf("Input the size of the array :");
    scanf("%d",&n);

    printf("\n\nEnter each element: \n\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
    }

    mergesort(array,n);

    printf("\n\nAfter Sorting: \n\n");
    for(i=0; i<n; i++)
        printf("%d ",array[i]);

    return 0;
}
