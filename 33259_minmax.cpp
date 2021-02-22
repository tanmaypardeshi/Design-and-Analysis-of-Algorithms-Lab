#include <bits/stdc++.h>
using namespace std;

bool check_sorted(int *, int);
void min_max(int *, int &, int &, int, int);

int main()
{
    int *arr, n, min = INT32_MAX, max = INT32_MIN;

    // Number of elements
    cout << "\nEnter the number of elements in the array:- ";
    cin >> n;
    arr = new int[n];

    // Input elements from the user
    cout << "\nEnter the elements:- \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << ":- ";
        cin >> arr[i];
    }

    // If already sorted then don't divide and conquer
    if (check_sorted(arr, n))
    {
        min = arr[0];
        max = arr[n - 1];
        cout << "\nFinal minimum in the Array:- " << min;
        cout << "\nFinal maximum in the Array:- " << max;
        cout << "\n";
        return 0;
    }

    // If not sorted then divide and conquer
    min_max(arr, min, max, 0, n - 1);
    cout << "\nFinal minimum in the Array:- " << min;
    cout << "\nFinal maximum in the Array:- " << max;

    cout << "\n";

    return 0;
}

bool check_sorted(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] >= arr[i])
            return false;
    }
    return true;
}

void min_max(int *arr, int &min, int &max, int start, int end)
{
    if (end - start <= 1)
    {
        if (arr[start] > max)
            max = arr[start];
        if (arr[end] > max)
            max = arr[end];
        if (arr[start] < min)
            min = arr[start];
        if (arr[end] < min)
            min = arr[end];
        cout << "\nArray is:- ";
        for (int i = start; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\nMinimum in the Array:- " << min;
        cout << "\nMaximum in the Array:- " << max << endl;
    }
    else
    {
        int mid = (start + end) / 2;
        cout << "\nArray is:- ";
        for (int i = start; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        min_max(arr, min, max, start, mid);
        min_max(arr, min, max, mid + 1, end);
    }
}
