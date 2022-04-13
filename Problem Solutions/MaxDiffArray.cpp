// https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
// Brute force- two loops, i and j. check every pair difference. TC will be O(N^2)
// Here, approach is based on formula maxDiff= elem(x) - min elem present before x.
// So, we can just find the min elem before current elem and calculate the max diff each time
// Here, TC is O(N) where N is the size of the array
#include <bits/stdc++.h>
using namespace std;

int maxDiff(int arr[], int n)
{
    int min = arr[0], maxdiff = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - min > maxdiff)
            maxdiff = arr[i] - min;

        if (arr[i] < min)
            min = arr[i];
    }
    return maxdiff;
}

void print(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
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
    cout << maxDiff(arr, n);
    return 0;
}