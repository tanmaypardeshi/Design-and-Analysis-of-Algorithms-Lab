/*----------------------------------------------------------------------------
Roll number: 33259
Division: 10
Batch: N 10
Problem Statement: Optimal storage in tapes.
----------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

float calculate_art(vector<int>);
float calculate_mrt(vector<int>);
int volume(vector<int>);

int main()
{
    vector<vector<int>> tapes;
    vector<int> original, sizes;

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
            cout << "\nCannot accommodate programs in the tapes!" << endl;
            return 0;
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

    cout << "\nAverage Retrieval Time of Tapes:-";
    cntr = 1;
    float art;
    for (auto x : tapes)
    {
        float temp = calculate_art(x);
        art += temp;
        cout << "\nAverage Retrieval time of tape " << cntr << ":- " << temp;
        cntr++;
    }
    cout << "\nTotal Average Retrieval Time of Tapes is:- " << art / no_tapes;
    cout << endl;

    cout << "\nMean Retrieval Time of Tapes:- ";
    cntr = 1;
    float mrt;
    for (auto x : tapes)
    {
        float temp = calculate_mrt(x);
        mrt += temp;
        cout << "\nMean Retrieval time of tape " << cntr + 1 << ":- " << temp;
        cntr++;
    }
    cout << "\nTotal Mean Retrieval Time of Tapes is:- " << mrt / no_tapes;
    cout << endl;
    return 0;
}

float calculate_art(vector<int> tape)
{
    if (tape.size() == 0)
        return 0;
    float rt = 0;
    for (int y = 0; y < tape.size(); y++)
        rt += tape[y];
    return rt / tape.size();
}

float calculate_mrt(vector<int> tape)
{
    if (tape.size() == 0)
        return 0;
    float rt = 0;
    for (int y = 0; y < tape.size(); y++)
        rt += rt + tape[y];
    return rt / tape.size();
}

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

/* Output - 

tanmay@Predator:~/Code/DAA$ ./a.out 
Enter the number of tapes:- 3

Enter the size of each tape:- 
Enter size of tape 0:- 50
Enter size of tape 1:- 50
Enter size of tape 2:- 50

Enter the number of programs:- 9

Enter the programs:- 
Enter the length of program 1:- 4
Enter the length of program 2:- 5
Enter the length of program 3:- 6
Enter the length of program 4:- 3
Enter the length of program 5:- 2
Enter the length of program 6:- 4
Enter the length of program 7:- 5
Enter the length of program 8:- 6
Enter the length of program 9:- 7

Original array is:- 4   5       6       3       2       4       5       6       7
Sorted array is:- 2     3       4       4       5       5       6       6       7

Contents of the tape are:- 
Tape number 1:- 2       4       6
Tape number 2:- 3       5       6
Tape number 3:- 4       5       7

Average Retrieval Time of Tapes:-
Average Retrieval time of tape 2:- 4
Average Retrieval time of tape 2:- 4.66667
Average Retrieval time of tape 2:- 5.33333
Total Average Retrieval Time of Tapes is:- 4.66667

Mean Retrieval Time of Tapes:- 
Mean Retrieval time of tape 2:- 7.33333
Mean Retrieval time of tape 2:- 9.33333
Mean Retrieval time of tape 2:- 11
Total Mean Retrieval Time of Tapes is:- 9.22222

*/