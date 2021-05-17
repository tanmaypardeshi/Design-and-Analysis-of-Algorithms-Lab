#include <bits/stdc++.h>
using namespace std;

int knapsack(int[], int[], int, int);

int main()
{
    int n, W;
    int *wt, *val;

    cout << "Enter the number of elements:- ";
    cin >> n;

    cout << "Enter the weight of knapsack:- ";
    cin >> W;

    wt = new int[n];
    val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of item " << i + 1 << ":- ";
        cin >> wt[i];
        cout << "Enter value of item " << i + 1 << ":- ";
        cin >> val[i];
    }

    int answer = knapsack(wt, val, W, n);

    cout << "Maximum total value in the knapsack:- " << answer << endl;

    return 0;
}

int knapsack(int wt[], int val[], int W, int n)
{
    int **dp = new int *[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[W + 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}