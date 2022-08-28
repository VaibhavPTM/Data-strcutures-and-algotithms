// Link : https://codeforces.com/problemset/problem/1506/C
// Topic :   brute force    implementation    strings    *1000
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
	string a,b;
	cin >> a >> b;
	int n = a.size(), m = b.size(), mx = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int tmx = 0;
			if(a[i] == b[j]) {
				int x = i, y = j;
				while(x < n && y < m && a[x++] == b[y++]) {
					tmx++;
				}
			}
			mx = max(mx, tmx);
		}
	}
//	cout << n << " " << m << " " << mx << endl;
	cout << (n - mx) + (m - mx) << endl;
	
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
