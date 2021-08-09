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
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int> , grater<int> >
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"

int arr[1001][1001];
int n, m, c;

int solve(){
    int dp[n+1][m+1];
    int x[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = INT_MAX - c;
            else dp[i][j] = min({arr[i-1][j-1],dp[i-1][j] + c, dp[i][j-1] + c});
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) x[i][j] = dp[i][j] + c + arr[i-1][j-1];
            else if(i == 1) x[i][j] = dp[i][j-1] + c + arr[i-1][j-1];
            else if(j == 1) x[i][j] = dp[i-1][j] + c + arr[i-1][j-1];
            else x[i][j] = min(dp[i-1][j] + c + arr[i-1][j-1], dp[i][j] + c + dp[i-1][j-1]);
        }
    }
    return x[n][m] + 1;
}

int main(){
    cin>>n>>m>>c;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<solve();
    return 0;
}