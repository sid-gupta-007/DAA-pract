#include <iostream>
using namespace std;
int main()
{
    int a[50], n;
    cout << "enter number of element: ";
    cin >> n;
    cout << "enter array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 1; j < n; j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
    cout << "sorted array:\n";
    for (int l = 0; l < n; l++)
    {
        cout << a[l] << " ";
    }
    return 0;
}