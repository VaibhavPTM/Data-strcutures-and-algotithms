// Link : https://codeforces.com/problemset/problem/1555/C
// Topic : brute force, constructive algorithms, dp, implementation
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

int main() {
    // https://codeforces.com/problemset/submission/1555/124427684
    // https://www.youtube.com/watch?v=G6Ttks97ZfI - you tube
    int t;
    cin >> t;
    while(t--) {
        int m;
        cin >> m;
        int arr[2][m];
        int dp[2][m];
        memset(dp,0,sizeof dp);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
            dp[i][0] = arr[i][0];
            for(int j = 1; j < m; j++) {
                dp[i][j] = dp[i][j-1] + arr[i][j];
            }
        }
        int res = dp[0][m-1] - dp[0][0];
        for(int i = 1; i < m; i++) {
            // cout << res << " ";
            res = min(res,max(dp[0][m-1] - dp[0][i], dp[1][i-1]));
        }
        cout << res << endl;
    }
    return 0;
}