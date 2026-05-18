#include <bits/stdc++.h>
using namespace std;

void sort_s(vector<int> &arr, int n){
    
    for(int i = 0; i < n-1; i++){
        int minidx = i;

        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minidx]){
                minidx = j;
            }
        }

        swap(arr[minidx], arr[i]);
    }
}

int main() {
    
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort_s(a, n);

    cout << "Sorted array: ";
    for(int x : a){
        cout << x << " ";
    }

    return 0;
}