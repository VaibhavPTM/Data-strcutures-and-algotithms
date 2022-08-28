// Link : https://codeforces.com/problemset/problem/1517/A
// Topic : 
#include<bits/stdc++.h>
#include<conio.h>
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
	lli n;
	cin >> n;
    lli k = n / 2050, res = 0;
    while(k) {
        res += k % 10;
        k /= 10;
    }
    if(n % 2050) cout << "-1"; else cout << res;
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