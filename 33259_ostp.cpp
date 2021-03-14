/*----------------------------------------------------------------------------
Roll number: 33259
Division: 10
Batch: N 10
Problem Statement: Optimal storage in tapes.
----------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int volume(vector<int> v)
{
    int total = 0;
    if (v.size() == 0)
    {
        return 0;
    }
    for (auto x : v)
    {
        total += x;
    }
    return total;
}
int main()
{
    vector<vector<int>> tapes;
    vector<int> original, sizes;

    float mrt;

    int no_tapes, no_programs, buffer, flag, cntr;

    cout << "Enter the number of tapes:- ";
    cin >> no_tapes;

    cout << "\nEnter the size of each tape:- " << endl;
    for (int i = 0; i < no_tapes; i++)
    {
        cout << "Enter size of tape " << i << ":- ";
        cin >> buffer;
        sizes.push_back(buffer);
        tapes.push_back(vector<int>());
    }

    cout << "\nEnter the number of programs:- ";
    cin >> no_programs;
    cout << "\nEnter the programs:- \n";
    for (int i = 0; i < no_programs; i++)
    {
        cout << "Enter the length of program " << i + 1 << ":- ";
        cin >> buffer;
        original.push_back(buffer);
    }

    cout << "\nOriginal array is:- ";
    for (auto x : original)
    {
        cout << x << "\t";
    }
    cout << endl;

    sort(original.begin(), original.end());

    cout << "Sorted array is:- ";
    for (auto x : original)
    {
        cout << x << "\t";
    }
    cout << endl;

    buffer = 0;

    for (int i = 0; i < no_programs; i++)
    {
        int j = buffer % tapes.size();
        if (sizes[j] >= volume(tapes[j]) + original[i])
        {
            flag = 0;
            tapes[j].push_back(original[i]);
        }
        else
        {
            i--;
            flag++;
        }
        buffer++;
        if (flag >= no_tapes)
        {
            break;
        }
    }

    cout << "\nContents of the tape are:- \n";
    cntr = 1;
    for (auto x : tapes)
    {
        cout << "Tape number " << cntr++ << ":- ";
        for (auto y : x)
        {
            cout << y << "\t";
        }
        cout << endl;
    }
}
