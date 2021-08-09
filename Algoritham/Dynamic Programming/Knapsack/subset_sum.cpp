// Link : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

bool subsetSum(int nums[], int n,int sum){
    bool dp[n+1][sum+1];
    for(int i = 0; i <=n; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i <= sum; i++){
        dp[0][i] = false;
    }
    for(int i = 1; i <=n; i++){
        for (int j = 1; j <= sum; j++)
        {
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
            }
            else 
            dp[i][j] = dp[i-1][j];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <- sum; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;   
    }
    
    return dp[n][sum];
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,sum;
        cin>>n>>sum;
        int nums[n];
        for(int i = 0; i < n; i++){
            cin>>nums[i];
        }
        if(subsetSum(nums,n,sum)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return 0;
    }
}