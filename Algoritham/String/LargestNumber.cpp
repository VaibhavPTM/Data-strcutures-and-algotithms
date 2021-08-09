// Link : https://leetcode.com/problems/largest-number/
// Topic : string, sorting
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
static bool cmp(string a, string b)
{
    return (a + b) > (b + a);
}
string largestNumber(vector<int> &nums)
{
    vector<string> v;
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(to_string(nums[i]));
    }
    sort(v.begin(), v.end(), cmp);
    string res = "";
    for (auto i : v)
        res += i;
    while (res.size() > 1 && res[0] == '0')
    {
        res.erase(res.begin());
    }
    return res;
}
int main()
{
    vi v = {24,5,423,9,7,95,99,0,86876};
    cout<<largestNumber(v);

    return 0;
}