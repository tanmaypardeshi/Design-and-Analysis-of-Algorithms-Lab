// Problem Statement - Find and display minimum and maximum numbers from an array

// Pseudo Code
// -------------------------------------------------------------------------------------
// int min = array[0], max = array[0]   (1)
// for i = 0 to (size of array):        (n+1)
//     if(array[i] < min):              (n)
//         min = array[i]               (n)
//     if(array[i] > max):              (n)
//         max = array[i]               (n)
// print(min, max)                      (1)
// -------------------------------------------------------------------------------------

// Complexity Analysis - Time complexity = O(n)
// -------------------------------------------------------------------------------------
// f = 1 + n + 1 + n + n + n + n + 1
// f = 5n + 3
// -------------------------------------------------------------------------------------

// Implementation
// -------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
    int *array;

    int n;

    cout << "Enter size of array:- ";
    cin >> n;

    array = new int[n];

    cout << "Enter elements in the array:- \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << ":- ";
        cin >> array[i];
    }

    int min = array[0], max = array[0];

    cout << "\nArray is:- ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";

        if (array[i] < min)
            min = array[i];
        if (array[i] > max)
            max = array[i];
    }
    cout << "\n\n";

    cout << "Maximum element is:- " << max << endl;
    cout << "Minimum element is:- " << min << endl;

    return 0;
}

// -------------------------------------------------------------------------------------
