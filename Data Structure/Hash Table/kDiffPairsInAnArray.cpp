// Link : https://leetcode.com/problems/k-diff-pairs-in-an-array/
// Topic : K-diff Pairs in an Array
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
int findPairs(vector<int> &nums, int k)
{
    int ans = 0;
    unordered_map<int, int> mp;
    for (int &i : nums)
    {
        mp[i]++;
    }
    for (auto &i : mp)
    {
        if (!k)
        {
            if (i.second > 1)
                ans++;
        }
        else
        {
            if (mp.find(i.first + k) != mp.end())
                ans++;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int t;
        cin>>t;
        v.push_back(t);
    }
    cout<<findPairs(v,k);
    return 0;
}