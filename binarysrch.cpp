#include<iostream>
using namespace std;

int binarySearch(int a[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}



int main(){
    int key;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nEnter element to search: ";
    cin >> key;
    int pos = binarySearch(arr, 0, n - 1, key);
    if (pos != -1)
        cout << "Element found after sorting at position " << pos + 1;
    else
        cout << "Element not found";

    return 0;


}