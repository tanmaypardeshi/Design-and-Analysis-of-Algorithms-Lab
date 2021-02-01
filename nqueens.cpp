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
    }

    return 0;
}

void printboard(int n)
{
    cout << "\nSolution " << ++cnt << ":- \n"
         << endl;
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
    if (k >= n + 1)
    {
        printboard(n);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (place(k, i) == 1)
        {
            board[k] = i;
            queen(k + 1, n);
            board[k] = 0;
        }
    }
}
