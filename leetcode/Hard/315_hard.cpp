// Link : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Topic :
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

class fenwick
{
public:
    vector<int> bit;
    fenwick(int n)
    {
        bit.assign(n, 0);
    }
    void update(int i, int val)
    {
        for (; i < bit.size(); i += i & (-i))
            bit[i] += val;
    }
    int get(int i)
    {
        int ans = 0;
        for (; i > 0; i -= i & (-i))
            ans += bit[i];
        return ans;
    }
};
vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    fenwick tree(mx - mn + 1 + 1);
    vector<int> cnt(n);
    for (int i = n - 1; i >= 0; i--)
    {
        cnt[i] = tree.get(nums[i] - mn);
        tree.update(nums[i] - mn + 1, 1);
    }
    return cnt;
}
int main()
{
    // Constraints:
    // 1 <= nums.length <= 105
    // -104 <= nums[i] <= 104  

    return 0;
}