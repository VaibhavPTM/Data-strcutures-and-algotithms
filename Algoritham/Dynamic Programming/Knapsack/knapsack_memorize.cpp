// Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

long int dp[1001][1001]; // dp[n][w];

int knapSack(int w, int wt[], int val[], int n) 
    { 
        if(w == 0 || n == 0){
            return 0;
        }
        else if(dp[n][w] != -1)
            return dp[n][w];
        else if(wt[n-1] <= w){
            return dp[n][w] =  max(val[n-1] + knapSack(w-wt[n-1],wt,val,n-1),knapSack(w,wt,val,n-1));
        }
        else{
            return dp[n][w] =  knapSack(w,wt,val,n-1);
        }
    }
int main()
{
    memset(dp, -1, sizeof dp);
    int w,n;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    cout<<knapSack(w,wt,val,n);
    return 0;
}