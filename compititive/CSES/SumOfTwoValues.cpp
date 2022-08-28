// Link : https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    map<int,int> mp;
    int n, k;
    vector<int> ar;
    ar.push_back(-1);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ar.push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        if(mp.find(ar[i]) != mp.end()) {
            cout << mp[ar[i]] << " " << i;
            return 0;
        }
        mp[k-ar[i]] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}