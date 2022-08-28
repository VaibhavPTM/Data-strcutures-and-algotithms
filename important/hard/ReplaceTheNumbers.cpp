// Link : https://codeforces.com/problemset/problem/1620/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool prime(ll n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
ll POW (ll a, ll p, ll m) { ll res = 1; while (p > 0) { if(p % 2 == 0){ p /= 2; a = ((a%m)*(a%m))%m; } else{ res = ((res%m)*(a%m))%m; p--; }}return res;}
#define TEST int t = 1; cin >> t; while(t--) solve();
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define p(A,B) pair<A,B>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define vec(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";cout << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define ps(x,y) fixed<<setprecision(y)<<x
#define mem(n,i) memset(n, i,sizeof n)
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
#define endl "\n"

void solve() {
	vec(int) mp(1000001);
	for(int i = 0; i <= 1000001; i++) {
		mp[i] = i;
	}
	int q;
	cin >> q;
	vv(int) qe;
	vec(int) res;
	while(q--) {
		int a, x;
		cin >> a >> x;
		if(a == 1) {
			mp[x] = x;
			qe.pb({a,x});
		}
		else {
			int y;
			cin >> y;
			qe.pb({a,x,y});
		}
	}
	for(int i = qe.size()-1; i >= 0; i--) {
		if(qe[i][0] == 1) {
			res.pb(mp[qe[i][1]]);
		}
		else {
			mp[qe[i][1]] = mp[qe[i][2]];
		}
	}
	for(int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}
	cout << endl;
}

int main() {
    SPEED
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
    // TEST
    solve();
    return 0;
}