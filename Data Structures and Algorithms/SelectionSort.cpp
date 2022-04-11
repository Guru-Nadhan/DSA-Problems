// Time Complexity is O(N^2), where N is the size of array.
// Space complexity is O(1)- inplace sorting
#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n)
{
    int i, j, min, t;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            t = arr[i];
            arr[i] = arr[min];
            arr[min] = t;
        }
    }
}

void print(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << arr[i];
        i++;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of Array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    print(arr, n);
    selectionSort(arr, n);
    print(arr, n);
    return 0;
}