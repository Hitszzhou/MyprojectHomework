#include <stdio.h>
#include <stdlib.h>
void Print(int*arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%-2d ",arr[i]);
    }
    printf("\n");
}
void QuickSort(int *arr,int L,int R)
{
    int voilt=arr[L];
    int left=L;
    int right=R;
    if(left>=right)
        return;
    while(left<right)
    {
        while(arr[right]<=voilt&&left<right)
        {
            right--;
        }
        if(left<right)
        {
            arr[left]=arr[right];
        }
        while(arr[left]>=voilt&&left<right)
        {
            left++;
        }
        if(left<right)
        {
            arr[right]=arr[left];
        }
    }
        arr[right]=voilt;
        QuickSort(arr,L,right-1);
        QuickSort(arr,left+1,R);
}
void DateSort(int arr[],int n)
{
    int i,k,j,temp;
    for(i=0;i<n-1;i++)
    {
         k=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[k])
                k=j;
        }

        if(k!=i)
        {
            temp=arr[k];
            arr[k]=arr[i];
            arr[i]=temp;
        }
    }

}
int main()
{
    int arr[]={1,5,8,7,3,9,11,1,6,3,8,9,0,6,0,0,4,3,2,3,4,5,4,3,2,4,5};
    int i,j,temp;

    int sz=sizeof(arr)/sizeof(arr[0]);
     Print(arr,sz);
    DateSort(arr,sz);
    Print(arr,sz);
    return 0;
}
