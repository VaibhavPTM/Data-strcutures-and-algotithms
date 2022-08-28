// Link : https://codeforces.com/problemset/problem/1512/C
// Topic : constructive algorithms    implementation    strings    *1200
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
void solve() {
    int a, b, n;
    string s;
    cin >> a >> b >> s;
    n = a+b;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') s[i] = s[n-i-1];
    }
    a -= count(s.begin(),s.end(),'0');
    b -= count(s.begin(),s.end(),'1');
    for(int i = 0; i <= n/2; i++) {
        if(i != n - i - 1 && s[i] == '?') {
            if(a > 1) s[i] = s[n-i-1] = '0',a-=2;
            else if(b > 1) s[i] = s[n-i-1] = '1',b-=2;
        }
        else if(s[i] == '?'){
            if(a) s[i] = '0',a--;
            else s[i] = '1',b--;
        }
    }
    string v = s;
    reverse(v.begin(),v.end());
    if(v == s && a == 0 && b == 0) cout << s << endl;
    else cout << "-1" << endl;

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