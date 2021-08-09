// Example 4
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
#define mx 1000000007
#define endl "\n"

int sum(int arr[], int n){
    int dp[n];
    if(arr[0] > 0) dp[0] = arr[0];
    else dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] + dp[i-1] > 0) dp[i] = arr[i] + dp[i-1];
        else dp[i] = 0;
    }
    int _max = 0;
    for (int i = 0; i < n; i++)
    {
        cout<<dp[i]<<" ";
        _max = max(_max,dp[i]);
    }
    cout<<endl;
    return _max;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"sum : "<<sum(arr,n);
    return 0;
}