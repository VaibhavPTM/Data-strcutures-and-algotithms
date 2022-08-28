// Link : https://www.codechef.com/CDMN21C/problems/SUBMEDIA
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
    int n, k;
    cin >> n >> k;
    int ar[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    int l, r;
    if(k&1) {
        l = r = (k-1)/2;
    }
    else {
        l = r = k/2;
        l--;
    }
    int mxi = l+1;
    for(int i = l+1; i <= n-r; i++) {
        if(ar[mxi] < ar[i]) {
            mxi = i;
        }
    }
    for(int i = 1; i <= l; i++) {
        cout << ar[i] << " ";
    }
    cout << ar[mxi] << " ";
    for(int i = n-r+1; i <= n; i++) {
        cout << ar[i] << " ";
    }
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