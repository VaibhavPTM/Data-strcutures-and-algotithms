// Link : https://codeforces.com/problemset/problem/1474/B
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
int isp(int x){
	if(x<2)return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
void solve() {
    int d;
    cin >> d;
    lli t1, t2;
    t1 = 1 + d;
    while(!isp(t1)) t1++;
    t2 = t1+d;
    while(!isp(t2)) t2++;
    cout << t1 * t2 << endl;
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