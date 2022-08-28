// Link : https://www.codechef.com/OCT21B/problems/DIGITREM
#include<bits/stdc++.h>
using namespace std;
#define lli long long
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
	lli n, d;
	cin >> n >> d;
	string t = to_string(n);
	int sz = t.size();
	if(d == 9) {
		if(t[0] == '9') {
			for(int i = 0; i < sz; i++) {
				t[i] = '0';
			}
			t = "1" + t;
		}
		else {
			int j = sz;
			for(int i = 0; i < sz; i++) {
				if(t[i] == '9') {
					for(int k = i-1; k >= 0; k--) {
						if(t[k] <= '7') {
							t[k] = t[k] + 1;
							j = k;
							goto cvv;
						}
					}
					for(int i = 0; i < sz; i++) {
						t[i] = '0';
					}
					t = "1" + t;
					goto fvv;
				}
			}
			cvv:;
			for (int i = j+1; i < sz; i++) {
				t[i] = '0';
			}
			fvv:;
			
		}
	}
	else if(d == 0) {
		int j = sz;
		for(int i = 0; i < sz; i++) { 
			if(t[i] == '0') {
				t[i] = '1';
				j = i;
				break;
			}
		}
		for(int i = j+1; i < sz; i++) {
			t[i] = '1';
		}
	}
	else {
		int i = 0;
		for(i = 0; i < sz; i++) { 
			if((t[i] - 48) == d) {
				t[i] = t[i]+1;
				break;
			}
		}
		for(int j = i+1; j < sz; j++) {
			t[j] = '0';
		}
	}
	lli n2 = stoll(t);
	cout << n2 - n << endl;
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