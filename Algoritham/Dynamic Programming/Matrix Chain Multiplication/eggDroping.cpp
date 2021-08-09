// gfg - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// leetcode - https://leetcode.com/problems/super-egg-drop/
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
vector<vector<int>> dp;
int solve(int e, int f)
{
    if (e == 1 || f == 0 || f == 1)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];
    int low = 1, hige = f;
    int res = INT_MAX;
    while (low <= hige)
    {
        int mid = low + (hige - low) / 2;
        int l, r;
        if (dp[e - 1][mid - 1] != -1)
            l = dp[e - 1][mid - 1];
        else
        {
            l = solve(e - 1, mid - 1);
            dp[e - 1][mid - 1] = l;
        }
        if (dp[e][f - mid] != -1)
            r = dp[e][f - mid];
        else
        {
            r = solve(e, f - mid);
            dp[e][f - mid] = r;
        }
        int worst = 1 + max(l, r);
        res = min(res, worst);

        if (l < r)
            low = mid + 1;
        else
            hige = mid - 1;
    }
    return dp[e][f] = res;
}
int superEggDrop(int e, int f)
{
    dp.resize(e + 1, vector<int>(f + 1, -1));
    return solve(e, f);
}
int main()
{
    int e, f;
    cin >> e >> f;
    int ans = superEggDrop(e, f);
    cout << ans;
    return 0;
}
/* ------> many more solutions
Recusive Code Time Complexity: O(n * (2^min(n,k))
int superEggDrop(int e, int f) {
    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;
    int ans = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int temp = max(superEggDrop(e - 1, k - 1), superEggDrop(e, f - k)) + 1;
        ans = min(ans, temp);
    }
    return ans;
    }
Memoization Time Complexity: O((n^2) * k)
vector<vector<int>> dp(101, vector<int> (10001, -1));
class Solution {
public:
    int superEggDrop(int e, int f)
    {

        if (e == 1)
            return f;
        if (f == 0 || f == 1)
            return f;

        if (dp[e][f] != -1)
            return dp[e][f];

        int ans = INT_MAX;
        for (int k = 1; k <= f; k++)
        {
            int temp = max(superEggDrop(e - 1, k - 1), superEggDrop(e, f - k)) + 1;
            ans = min(ans, temp);
        }
        return dp[e][f] = ans;
    }
Memoization With Optimization (giving TLE on leetcode)
If dp[e][f] was -1 we straightaway called for F(e-1,f-1) & F(e,f-k)...without checking if they were already calculated. Let us optimize the abova approach
Code
  int superEggDrop(int e, int f)
{

    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int low, high;
        if (dp[e - 1][k - 1] != -1)
            low = dp[e - 1][k - 1];
        else
            low = superEggDrop(e - 1, k - 1);
        if (dp[e][f - k] != -1)
            high = dp[e][f - k];
        else
            high = superEggDrop(e, f - k);
        int temp = max(low, high) + 1;
        ans = min(ans, temp);
    }
    return dp[e][f] = ans;
}
Better Method(Accepted on Leetcode) ||
    80 ms runtime(O(N ^ 2 * logN) time)
        Instead of iterating 'k' linearly we can do binary search and do the same with 'mid' instead of K int
        solve(int e, int f, vector<vector<int>> &dp)
{
    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX;

    int low = 1, high = f;
    while (low <= high)
    {

        int mid = (low + high) / 2;

        int left = solve(e - 1, mid - 1, dp);

        int right = solve(e, f - mid, dp);

        int temp = max(left, right) + 1;
        ans = min(ans, temp);

        if (left < right)  //since right is more than left and we need more in wrost case
            low = mid + 1; // so l=mid+1 to gain more temp for worst case: upward
        else               //left > right so we will go downward
            high = mid - 1;
    }
    return dp[e][f] = ans;
}
int superEggDrop(int e, int f)
{
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    return solve(e, f, dp);
}
Much Better than above solution ( 68 ms on leetcode)
If dp[e][f] was -1 we straightaway called for F(e-1,f-1) & F(e,f-k)...without checking if they were already calculated. Let us optimize this
 int solve(int e, int f, vector<vector<int>>&dp)
{
    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX;

    int low = 1, high = f;
    while (low <= high)
    {
        int left, right;
        int mid = (low + high) / 2;

        if (dp[e - 1][mid - 1] != -1)
            left = dp[e - 1][mid - 1];
        else
            left = solve(e - 1, mid - 1, dp);

        if (dp[e][f - mid] != -1)
            right = dp[e][f - mid];
        else
            right = solve(e, f - mid, dp);

        int temp = max(left, right) + 1;
        ans = min(ans, temp);

        if (left < right)  //since right is more than left and we need more in wrost case
            low = mid + 1; // so l=mid+1 to gain more temp for worst case: upward
        else               //left > right so we will go downward
            high = mid - 1;
    }
    return dp[e][f] = ans;
}
int superEggDrop(int e, int f)
{
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    return solve(e, f, dp);
}
O(N * K)
solution : (I aam crying)

               dp[M][K] means that,
           given K eggs and M moves,
           what is the maximum number of floor that we can check.int superEggDrop(int K, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    int m = 0;
    while (dp[m][K] < N)
    {
        m++;
        for (int k = 1; k <= K; ++k)
            dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
    }
    return m;
}
Most optimal O(KlogN)(dead) int superEggDrop(int K, int N)
{
    vector<int> dp(K + 1, 0);
    int m;
    for (m = 0; dp[K] < N; m++)
        for (int k = K; k > 0; --k)
            dp[k] += dp[k - 1] + 1;
    return m;
}
*/