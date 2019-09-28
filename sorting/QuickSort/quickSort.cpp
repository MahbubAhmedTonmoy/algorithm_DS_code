
#include <stdio.h>

int array[1000],low,high,temp;

void quicksort(int pivot, int last)
{
    if(pivot<last)
    {
        low=pivot+1;
        high=last;
        while(array[low]<=array[pivot])
            low++;

        while(array[high]>array[pivot])
            high--;

        while(low<high)
        {
            temp=array[high];
            array[high]=array[low];
            array[low]=temp;

            while(array[low]<array[pivot])
                low++;

            while(array[high]>array[pivot])
                high--;
        }

        temp=array[high];
        array[high]=array[pivot];
        array[pivot]=temp;

        quicksort(pivot,high-1);
        quicksort(high+1,last);
    }

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

    quicksort(0,n-1);

    printf("\n\nAfter Sorting: \n\n");
    for(i=0; i<n; i++)
        printf("%d ",array[i]);

    return 0;
}
