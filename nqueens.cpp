#include <bits/stdc++.h>
#define N 100
using namespace std;

int board[N];
int cnt = 0;

void queen(int, int);
void printboard(int);
int place(int, int);

int main()
{
    int n;

    cout << "Enter number of queens:- ";
    cin >> n;

    if (n < 4)
    {
        cout << "\nNo solutions exist for the given input!\n\n";
    }
    else
    {
        queen(1, n);

        if (!cnt)
        {
            cout << "\nNo solutions exist for the given input!\n";
        }
        else
        {
            cout << "\n"
                 << cnt << " solutions printed.\n ";
        }
    }

    return 0;
}

void printboard(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                cout << "1  ";
            }
            else
            {
                cout << "0  ";
            }
        }
        cout << endl;
    }
}

int place(int k, int i)
{
    for (int j = 1; j <= k; j++)
    {
        if ((board[j] == i) || board[j] - j == i - k || board[j] + j == i + k)
        {
            return 0;
        }
    }
    return 1;
}

void queen(int k, int n)
{
    int i;
    if (!cnt)
    {
        cout << "\nThis step modifications:\n";
        printboard(n);
    }

    if (k >= n + 1)
    {
        cnt++;
        if (cnt == 1)
        {
            cout << "\n------------------------------------------------";
        }
        cout << "\nPossible solutuion no. " << cnt << ":\n";
        printboard(n);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (place(k, i) == 1)
        {
            board[k] = i;
            queen(k + 1, n);
            if (!cnt)
            {
                cout << "Backtracking previous queen...\n";
            }
            board[k] = 0;
        }
    }
}

// tanmay@Predator:~/Code/DAA$ g++ nqueens.cpp
// tanmay@Predator:~/Code/DAA$ ./a.out
// Enter number of queens:- 4

// This step modifications:
// 0  0  0  0
// 0  0  0  0
// 0  0  0  0
// 0  0  0  0

// This step modifications:
// 1  0  0  0
// 0  0  0  0
// 0  0  0  0
// 0  0  0  0

// This step modifications:
// 1  0  0  0
// 0  0  1  0
// 0  0  0  0
// 0  0  0  0
// Backtracking previous queen...

// This step modifications:
// 1  0  0  0
// 0  0  0  1
// 0  0  0  0
// 0  0  0  0

// This step modifications:
// 1  0  0  0
// 0  0  0  1
// 0  1  0  0
// 0  0  0  0
// Backtracking previous queen...
// Backtracking previous queen...
// Backtracking previous queen...

// This step modifications:
// 0  1  0  0
// 0  0  0  0
// 0  0  0  0
// 0  0  0  0

// This step modifications:
// 0  1  0  0
// 0  0  0  1
// 0  0  0  0
// 0  0  0  0

// This step modifications:
// 0  1  0  0
// 0  0  0  1
// 1  0  0  0
// 0  0  0  0

// This step modifications:
// 0  1  0  0
// 0  0  0  1
// 1  0  0  0
// 0  0  1  0

// ------------------------------------------------
// Possible solutuion no. 1:
// 0  1  0  0
// 0  0  0  1
// 1  0  0  0
// 0  0  1  0

// Possible solutuion no. 2:
// 0  0  1  0
// 1  0  0  0
// 0  0  0  1
// 0  1  0  0

// 2 solutions printed.
//  tanmay@Predator:~/Code/DAA$