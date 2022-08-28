// Link : https://codeforces.com/problemset/problem/1523/A
// Topic : 
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl "\n"
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "0" + s + "0";
    string p = s;
    while(k--) {
        for(int i = 1; i <= n; i++){
            // '0' + '1'
            if(p[i-1] + p[i+1] == 97) s[i] = '1';
        }
        if(s == p) break;
        p = s;
    }
    for(int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}