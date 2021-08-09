// Link : https://leetcode.com/problems/candy/
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, grater<int>>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"
int candy(vector<int> &rat)
{
    int n = rat.size();
    vector<int> can(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (rat[i] < rat[i + 1])
        {
            can[i + 1] = can[i] + 1;
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (rat[i] < rat[i - 1])
        {
            can[i - 1] = max(can[i - 1], can[i] + 1);
        }
    }
    int res = 0;
    for (int i : can)
        res += i;

    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.pb(t);
    }
    cout << candy(arr);
    return 0;
}