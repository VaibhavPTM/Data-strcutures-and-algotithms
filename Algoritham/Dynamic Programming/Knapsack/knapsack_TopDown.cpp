// Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();


long int knapSack(int w, int wt[], int val[], int n)
{
    long int dp[n+1][w+1]; // dp[n][w];
    for(int i = 0; i <= n; i++){  // here j represents the weight
        for(int j = 0; j <= w; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]] , dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // Printing knapsack 
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][w];
}
int main()
{
    int w, n;
    cin >> n >> w;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << knapSack(w, wt, val, n);
    return 0;
}