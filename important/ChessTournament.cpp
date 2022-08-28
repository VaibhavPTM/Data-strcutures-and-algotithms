// Link : 
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
	string s;
	cin >> n >> s;
	int a1 = count(s.begin(), s.end(), '1');
	int a2 = count(s.begin(), s.end(), '2');
	if(a2 == 2 || a2 == 1) {
		cout << "NO" << endl;
		return;
	}
	vector<string> res;
	for(int j = 0; j < n; j++) {
		string t;
		for(int i = 0; i < n; i++) {
			if(i == j) t.push_back('X');
			else
				t.push_back('=');
		}
		res.push_back(t);
	}
	for(int i = 0; i < n; i++) {
		bool flg = false;
		for (int j = 0; j < n; j++) {
			if(s[i] == '1' || s[j] == '1') continue;
			if(i != j && res[i][j] == '=') {
				if(!flg) {
					res[i][j] = '+';
					res[j][i] = '-';
					flg = true;
				}
				else {
					res[i][j] = '-';
					res[j][i] = '+';
				}
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}
int main() {
	system("cls");
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