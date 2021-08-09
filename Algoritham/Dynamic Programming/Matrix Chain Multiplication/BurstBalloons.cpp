// Link : https://leetcode.com/problems/burst-balloons/
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define si set<int>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define mod 1000000007
#define sin(n) scanf("%d",&n)
#define endl "\n"

int dp[1001][1001];
int maxCoins(vector<int>& nums,int i, int j) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int res = INT_MIN;
    for (int k = i; k < j; k++)
    {
        int mx = maxCoins(nums,i,k) + maxCoins(nums,k+1,j) + (nums[i-1] * nums[j] * nums[k]);
        res = max(res,mx);
    }
    return dp[i][j] = res;
}
int main(){
    memset(dp, -1, sizeof dp);
    int n;
    sin(n);
    vi arr(n);
    for (int i = 0; i < n; i++){
        sin(arr[i]);
    }
    arr.insert(arr.begin(),1);
    arr.push_back(1);
    cout<<"Output: "<<maxCoins(arr,1,arr.size()-1);
    
    return 0;
}