// Link : https://codeforces.com/problemset/problem/1520/E
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
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
	string s;
	cin >> s;
	int cnt = 0;
	for(auto x : s)
		cnt += (x == '*' ? 1 : 0);
	int pos = -1;
	int cur = -1;
	for(int i = 0; i < n; i++)
	{
	 	if(s[i] == '*')
	 	{
	 	    cur++;
	 	    if(cur == cnt / 2)
	 	    	pos = i;
	 	}	
	}
	long long ans = 0;
	cur = pos - cnt / 2;
	for(int i = 0; i < n; i++)
		if(s[i] == '*')
		{
		 	ans += abs(cur - i);
		 	cur++;
		}
	cout << ans << endl;
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