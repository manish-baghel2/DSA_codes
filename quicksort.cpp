// #include<bits/stdc++.h>
// using namespace std;

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[low];
//     int count = 0;
//     for(auto i = low; i<=high;i++){
//         if(arr[i]<=pivot) count++;
//     }
//     int index = count+low;
//     swap(arr[low],arr[index]);
//     int i = low, j = high;;
//     while(i<index and j>index){
//         while(arr[i]<pivot) i++;
//         while(arr[j]>pivot) j--;
//         if(i<index and j>index){
//             swap(arr[i],arr[j]);
//             i++,j--;
//         }
//     }
//     return index;
// }

// void quicksort(int arr[], int low, int high)
// {
//     if(low>=high) return;
//     int p = partition(arr, low, high);
//     quicksort(arr, low, p-1);
//     quicksort(arr, p+1, high);
// }

// int main(){
//     int arr[] = {1, 4, 5, 2, 3};
//     quicksort(arr, 0, 4);
//     for(auto i: arr){
//         cout<<i<<" ";
//     }
// }
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int count = 0;
    for(auto i = low; i<=high;i++){
        if(arr[i]<=pivot) count++;
    }
    int index = count+low;
    swap(arr[low],arr[index]);
    int i = low, j = high;;
    while(i<index and j>index){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<index and j>index){
            swap(arr[i],arr[j]);
            i++,j--;
        }
    }
    return index;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if(low>=high) return;
    int p = partition(arr, low, high);
    quicksort(arr, low, p-1);
    quicksort(arr, p+1, high);
}

int main()
{
    vector<int> arr = {3, 1, 4, 2, 5};
    quicksort(arr, 0, arr.size() - 1);
    for (auto x : arr) {
        cout << x << " ";
    }
    return 0;
}
