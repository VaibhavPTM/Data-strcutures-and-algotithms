// Link : https://codeforces.com/problemset/problem/1496/B
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
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
void solve() {
    int n, k, res = n, mx, smi;
    cin >> n >> k;
    set<int> s;
    int ar[n];
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        s.insert(ar[i]);
    }
    sort(ar,ar+n);
    smi = 0;
    while (s.find(smi) != s.end()) smi++;
    mx = ar[n-1];
    if(k == 0) {
        cout << s.size() << endl;
        return;
    }
    if(smi > mx) {
        cout << s.size() + k << endl;
        return;
    }
    int t = ceil((double)(mx + smi)/2.0);
    if(s.find(t) == s.end()) {
        cout << s.size() + 1 << endl;
    }
    else cout << s.size() << endl;
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