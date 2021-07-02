#include<bits/stdc++.h>
using namespace std;

// merging the array's element with sorting them along the way
void merge(int arr[], int l, int mid, int r)
{
    int i=l, j = mid+1, k = 0;
    int temp[r-l+1];
    while(i<=mid and j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++,k++;
        }else{
            temp[k] = arr[j];
            j++, k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++, k++;
    }
    while(j<=r)
    {
        temp[k]=arr[j];
        j++, k++;
    }

    for(int p=l;p<=r;p++)
    {
        arr[p] = temp[p-l];
    }
}

// dividing the array into smaller pieces
void mergesort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }

}

int main()
{
    int arr[] ={9, 3, 7, 4, 6};
    mergesort(arr, 1, 4);
    for(int i=0;i<=4;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}