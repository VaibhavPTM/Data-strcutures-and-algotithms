// Link : https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
/*
Pseudo Code: 
DP[l+1]={-1}
DP[0]=0
for(i from 0 to l)
  if(DP[i]==-1)
  continue
  DP[i+p]=max(DP[i+p],DP[i]+1)
  DP[i+q]=max(DP[i+q],DP[i]+1)
  DP[i+r]=max(DP[i+r],DP[i]+1)
print(DP[l])

*/
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

int maximizeTheCuts(int sum, int x, int y, int z)
{
    int dp[sum + 1];
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[i] == -1)
        {
            continue;
        }
        if (x + i <= sum)
        {
            dp[x + i] = max(dp[x + i], 1 + dp[i]);
        }
        if (y + i <= sum)
        {
            dp[y + i] = max(dp[y + i], 1 + dp[i]);
        }
        if (z + i <= sum)
        {
            dp[z + i] = max(dp[z + i], 1 + dp[i]);
        }
    }
    if (dp[sum] == -1)
        dp[sum] = 0;
    return dp[sum];
}
int main()
{
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    cout<<maximizeTheCuts(n,x,y,z);
    return 0;
}