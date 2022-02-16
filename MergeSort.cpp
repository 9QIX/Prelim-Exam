#include <iostream>
using namespace std;

// function to merge the sub-arrays
void merge(int arr[],int l,int m, int r){
    int i = l, j = m + 1, k = l, temp[5];

    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++; k++;
        }
        else{
            temp[k] = arr[j];
            j++; k++;
        }
    }
    // add elements left in the first interval
    while(i <= m){
        temp[k] = arr[i];
        i++; k++;
    }
    // add elements left in the second interval
    while(j <= r){
        temp[k] = arr[j];
        j++; k++;
    }
    // copy temp to original interval
    for(int s = l; s <= r; s++){
        arr[s] = temp[s];
    }
}

// merge sort function [O(n log n)]
void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// driver code
int main() {
    int arr[6];

    cout << "Merge Sort Algorithm" << endl;
    // user input
    cout << "Enter 6 Integers: ";
    for (int &i: arr) {
        cin >> i;
    }
    // unsorted
    cout << "Unsorted Array: ";
    for (int i: arr) {
        cout << i << " ";
    }
    // sorted
    mergeSort(arr, 0, 5);
    cout << endl << "Sorted Array: ";
    for (int i: arr) {
        cout << i << " ";
    }
}