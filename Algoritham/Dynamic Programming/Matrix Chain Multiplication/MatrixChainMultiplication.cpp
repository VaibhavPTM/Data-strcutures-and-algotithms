// Link : https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
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

int dp[101][101];

int matrixMultiplication(int arr[], int i, int j) {
    if(i >= j) return 0;
    int res = INT_MAX;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    for (int k = i; k < j; k++)
    {
        int _min = matrixMultiplication(arr,i,k) + matrixMultiplication(arr,k+1,j) + (arr[i-1] * arr[j] * arr[k]);
        res = min(res,_min);
    }
    dp[i][j] = res;
    return res;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int n;
    sin(n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        sin(arr[i]);
    }
    cout<<"Min cost is : "<<matrixMultiplication(arr, 1, n-1);
    
    return 0;
}