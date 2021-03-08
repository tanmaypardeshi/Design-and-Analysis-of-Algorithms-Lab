#include <iostream>
#define SIZE 100
using namespace std;

void divide(int[], int, int);
void merge(int[], int, int, int, int);
int calculate_time(int[], int[], int);

int size;

int main()
{
    int n, *size, *time, totalTime;
    cout << "How many programs are there:- ";
    cin >> n;
    size = new int(sizeof(int) * n);
    time = new int(sizeof(int) * n);
    cout << "Enter the retrival time of each program:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":- ";
        cin >> size[i];
    }

    divide(size, 0, n - 1);
    cout << "\nOrder is:- { ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << size[i] << " }" << endl;
            break;
        }
        cout << size[i] << " ";
    }
    totalTime = calculate_time(size, time, n);
    cout << "Average seek time is : " << (float)totalTime / n << endl;
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
    int temp[SIZE];

    while (a <= right1 && b <= right2)
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

int calculate_time(int *size, int *array, int n)
{
    array[0] = size[0];
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        array[i] = array[i - 1] + size[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}