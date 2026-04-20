#include <iostream>
using namespace std;

void insertSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) 
        // while (prev >= 0 && arr[prev] < curr)   // FOR descending order
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 3, 2};
    insertSort(arr, n);
    printArray(arr, n);

    return 0;
}