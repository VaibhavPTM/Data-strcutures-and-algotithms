// Link : 
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
    int n, k;
    cin >> n >> k;
    lli res = 0;
    int ar[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    sort(ar+1,ar+n+1,greater<int>());
    int mxVal = ar[1];
    int i = 1;
    // while(i < n && ar[i] == ar[i+1]) i++;
    while(k > 0 && mxVal > 0) {
        while(i < n && mxVal == ar[i+1])i++;
        if(i < k) {
            res += (mxVal * i);
            mxVal--;
            k -= i;
            // cout << mxVal << " " << i << " " << res <<endl;
        }
        else {
            res += mxVal*k;
            k = 0;
        }
    }
    cout << res;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}