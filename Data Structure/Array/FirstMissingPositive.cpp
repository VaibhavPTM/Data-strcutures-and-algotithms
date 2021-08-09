// Link : https://leetcode.com/problems/first-missing-positive/
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
// Using hashtable
int firstMissingPositive(vector<int> &nums){
    map<int, int> mp;
    for (int i : nums){
        mp[i];
    }
    int res = 1;
    for (auto i : mp){
        if (i.first > 0 && res == i.first){
            res++;
        }
        else if (i.first > 0)
            break;
    }
    return res;
}
// Using sorting
int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int res = 0;
    for(int i = 0; i < nums.size();i++){
        if(res+1 == nums[i]){
            res = nums[i];
        }
        else if(nums[i] > 0 && i > 0 && nums[i] != nums[i-1]) break;
    }
    return res+1;
}

int main()
{

    return 0;
}