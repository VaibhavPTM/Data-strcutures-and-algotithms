// Link : https://codeforces.com/problemset/problem/1433/D
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
    int n;
    cin >> n;
    vector<pair<int,int>> ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i].first;
        ar[i].second = i+1;
    }
    sort(ar.begin(),ar.end());
    if(ar[0].first == ar[n-1].first) {
        cout << "NO" << endl;
        return;
    }
    int i = n-1;
    int t = 0;
    cout << "YES" << endl;
    while(ar[0].first != ar[i].first) {
        cout << ar[0].second << " " << ar[i--].second << endl;
        t++;
    }
    i = 1;
    while(i < n && ar[n-1].first != ar[i].first && t < n-1) {
        t++;
        cout << ar[i++].second << " " << ar[n-1].second << endl;
    }
    

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