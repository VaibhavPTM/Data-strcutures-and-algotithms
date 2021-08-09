// Link : https://leetcode.com/problems/jump-game/
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
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define fors(j, s, n) for (int j = s; j < n; j++)
#define mod 1000000007
#define sin(n) scanf("%d", &n)
#define endl "\n"

bool canJump(vi nums)
{
    int jump = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > jump)
            return false;
        jump = max(jump, i + nums[i]);
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    vi v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    if (canJump(v))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}