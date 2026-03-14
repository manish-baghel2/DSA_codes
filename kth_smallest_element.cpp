#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; j ++) {
        if(arr[j] < pivot) {
            i  = i+ 1;
            int tmp = arr[i] + arr[j];
            arr[i] = tmp - arr[i];
            arr[j] = tmp - arr[i];
            // swap(arr[i], arr[j]);
        }
    }
    int tmp = arr[i+1] + arr[high];
    arr[i+1] = tmp - arr[i+1];
    arr[high] = tmp - arr[i+1];
    // swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}


int kthSmallest(vector<int> &arr, int k) {
    // code here
    if(arr.size() == 1 && k == arr.size()) return arr[0];
    quicksort(arr, 0, arr.size()-1);
    for(int i = 0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return arr[k-1];
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, k) << endl;
    return 0;
}