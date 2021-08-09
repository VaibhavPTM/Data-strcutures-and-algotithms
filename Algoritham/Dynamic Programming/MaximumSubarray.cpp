// https://www.hackerrank.com/challenges/maxsubarray/problem
// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
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
#define mx 1000000007
#define endl "\n"

vector<int> help(int arr[], int n)
{
    int res1 = INT_MIN, _max = 0;
    int res2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            res2 += arr[i];
        _max += arr[i];
        res1 = max(res1, _max);
        if (_max < 0)
        {
            _max = 0;
        }
    }
    if (res1 < 0)
        res2 = res1;
    return {res1, res2};
}

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = help(arr, n);
    cout << "Maximum subset sum : " << ans[0] << "\nMaximum sub sequence sum : " << ans[1];
    return 0;
}

// kadana's algorithem
// int maxSubArray(vector<int> &nums)
// {
//     int sum = 0, res = INT_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum = max(nums[i], sum + nums[i]);
//         res = max(res, sum);
//     }
//     return res;
// }