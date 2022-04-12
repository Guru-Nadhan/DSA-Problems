// Time Complexity is O(N^2), where N is the size of array.
// Space complexity is O(1)- inplace sorting
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int a[], int n)
{
    int temp;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false)
            return;
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
    bubbleSort(arr, n);
    print(arr, n);
    return 0;
}