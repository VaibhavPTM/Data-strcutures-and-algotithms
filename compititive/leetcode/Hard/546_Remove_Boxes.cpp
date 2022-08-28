#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"
vector<vector<vector<int>>> dp;
int help(vector<int> &box, int i, int j, int same) {
    if(i > j) return 0;
    else if(i == j) return same * same;
    else if(dp[i][j][same] != -1) return dp[i][j][same];
    dp[i][j][same] = (same * same) + help(box,i+1,j,1);
    for(int k = i + 1; k <= j; k++) {
    if (box[i] == box[k]) 
         dp[i][j][same] = max(dp[i][j][same], help(box, i + 1, k - 1, 1) + help(box, k, j, same + 1));
    }
    return dp[i][j][same];
}
int removeBoxes(vector<int>& box) {
    int n = box.size();
    dp.resize(101,vector<vector<int>>(101,vector<int>(101,-1)));
    return help(box,0,n-1,1);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int  i = 0; i < n; i++) cin >> v[i];
    cout << removeBoxes(v);
    return 0;
}