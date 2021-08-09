// Name : Divide Two Integers
// Link : https://leetcode.com/problems/divide-two-integers/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

#define iil long long int
#define vi vector<int>
#define si set<int>
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define fors(j, s, n) for (int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"
using namespace std;

int solve(int x, int y)
{
    if(x == 0)return 0;
    int min = y, ans = 1;
    while (min <= x)
    {
        if (y == x)
        {
            if(y < 0)return ans - (ans+ans);
            return ans;
        }
        else if (abs(min) + abs(y) > x)
        {
            break;
        }
        else
        {
            min += y;
            ++ans;
        }
    }
    if(y < 0)return ans - (ans+ans);
    return ans;
}

int main()
{
    cout << solve(-1 ,1);
    return 0;
}