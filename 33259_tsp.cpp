#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist;
vector<vector<int>> dp;
int n, visited;

int tsp(int, int);

int main()
{
    cout << "Enter number of cities:- ";
    cin >> n;

    visited = (1 << n) - 1;

    cout << "Enter the distance matrix:- " << endl;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;

        for (int j = 0; j < n; j++)
        {
            cout << "Enter cost for [" << i << "][" << j << "]:- ";
            int t;
            cin >> t;
            temp.push_back(t);
        }
        dist.push_back(temp);
    }

    cout << "\nMatrix is:- " << endl;

    for (auto x : dist)
    {
        for (auto y : x)
        {
            cout << y << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(-1);
        }
        dp.push_back(temp);
    }

    cout << "\nTravelling salesman distance is:- " << tsp(1, 0) << endl;
    return 0;
}

int tsp(int mask, int pos)
{

    if (mask == visited)
    {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT32_MAX;

    for (int city = 0; city < n; city++)
    {

        if ((mask & (1 << city)) == 0)
        {

            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}