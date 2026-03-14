#include<bits/stdc++.h>
using namespace std;

void partition(vector<int>& arr, int low, int high) {
        int pivot = 1;
        int i = low -1;
        int t = high+1;
        for(int j = low; j < high ; j ++) {
            if(arr[j] < pivot) {
                i = i +  1;
                int tmp = arr[i]+ arr[j];
                arr[j] = tmp - arr[j];
                arr[i] = tmp - arr[j];
            } else if(arr[j] > pivot) {
                t = t-1;
                for(int k = t ; k > 0; k--) {
                    if(arr[k] == 2) --t;
                    else break;
                }
                cout<<t<<" "<<arr[t]<<endl;
                int tmp = arr[j] + arr[t];
                arr[j] = tmp - arr[j];
                arr[t] = tmp - arr[j];
                for(auto i : arr) cout<<i<<" ";
                cout<<endl;
            }
        }
        // int tmp = arr[i+1] + arr[high];
        // arr[i+1] = tmp - arr[i+1];
        // arr[high] = tmp - arr[i+1];
    }
    void sort012(vector<int>& arr) {
        // code here
        partition(arr, 0, arr.size()-1);
    }

    int main() {
        vector<int> arr = {0, 1, 2, 0, 1, 2};
        sort012(arr);
        for(int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    }