// Link : https://codeforces.com/problemset/problem/1521/A
// Topic :  constructive algorithms    math    number theory    *1000
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
#define MAX 100001

int arr[MAX];

void solve() {
    lli a, b;
    cin >> a >> b;
    if(b == 1) cout << "NO" << endl;
    else cout << "YES" << endl << a << " " << a * b << " " << a * (b + 1) << endl;
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