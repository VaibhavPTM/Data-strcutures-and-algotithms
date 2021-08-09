// Name : Partition Equal Subset Sum 
// Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

bool IsEqual(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    if((sum & 1) == 1) return false;

    sum = sum/2;
    bool dp[n+1][sum+1];

    for (int i = 0; i <= n; i++){
        dp[i][0] = true;
    }
    for (int i = 1; i <= sum; i++){
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(j >= arr[i-1]){
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    if(IsEqual(arr,n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
        
    return 0;
}