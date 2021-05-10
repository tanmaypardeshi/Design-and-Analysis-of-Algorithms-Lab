#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value, weight;

    Item() {}
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool compare(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, compare);

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main()
{
    int W;
    int n;
    int weight, value;

    cout << "Enter total capacity of knapsack:- ";
    cin >> W;

    cout << "Enter number of items:- ";
    cin >> n;

    Item *arr = new Item[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of object " << i + 1 << ":- ";
        cin >> weight;
        cout << "Enter value of object " << i + 1 << ":- ";
        cin >> value;
        arr[i].weight = weight;
        arr[i].value = value;
    }

    cout << "Maximum value we can obtain: "
         << fractionalKnapsack(W, arr, n) << endl;

    delete[] arr;
    return 0;
}
