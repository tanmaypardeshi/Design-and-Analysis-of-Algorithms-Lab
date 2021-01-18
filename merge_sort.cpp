#include <iostream>
using namespace std;

void divide(int[], int, int);
void merge(int[], int, int, int, int);

int main()
{
    int *array;
    int size;

    cout << "Enter size of array:- ";
    cin >> size;

    array = new int[size];

    cout << "Enter elements in the array:- " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << ":- ";
        cin >> array[i];
    }

    cout << "Unsorted array is:- ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    divide(array, 0, size);

    cout << "After sorting, array is:- ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    return 0;
}

void divide(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        divide(array, left, mid);
        divide(array, mid + 1, right);
        merge(array, left, mid, mid + 1, right);
    }
}

void merge(int array[], int left1, int right1, int left2, int right2)
{
    int a = left1, b = left2, k = 0;
    int *temp = new int[right2];

    while (a < right1 && b < right2)
    {
        if (array[a] < array[b])
        {
            temp[k] = array[a];
            a++;
        }
        else
        {
            temp[k] = array[b];
            b++;
        }
        k++;
    }
    while (a <= right1)
    {
        temp[k] = array[a];
        a++;
        k++;
    }
    while (b <= right2)
    {
        temp[k] = array[b];
        b++;
        k++;
    }
    k = 0;

    for (a = left1; a <= right2; a++)
    {
        array[a] = temp[k];
        k++;
    }
}