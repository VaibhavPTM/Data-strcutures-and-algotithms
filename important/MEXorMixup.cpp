// Link : 
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
int ar[300001];
void solve() {  
	int a, b;
	cin >> a >> b;
	int x = ar[a-1];
	if(x == b) cout << a << endl;
	else if((x ^ b) != a){
		cout << a + 1 << endl;
	}
	else cout << a + 2 << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i < 300001; i++){
         ar[i] = ar[i-1] ^ i;		
    }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}