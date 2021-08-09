// Link : https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();


int solve(int nums[], int n, int sum){
    int dp[n+1][sum+1];

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= sum; i++){
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=sum ; j++)
        {
            if(j >= nums[i-1]){
                dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <=sum ; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return dp[n][sum];
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,n,sum);
    
    return 0;
}