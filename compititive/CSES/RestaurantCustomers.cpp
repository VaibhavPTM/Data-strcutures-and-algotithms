// Link : https://cses.fi/problemset/task/1619
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> ar;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ar.push_back({x,1});
        ar.push_back({y,-1});
    }
    sort(ar.begin(),ar.end());
    int res = 0, t = 0;
    for(auto &i : ar) {
        t += i.second;
        res = max(res,t);
    }
    cout << res << endl;
    return 0;
}