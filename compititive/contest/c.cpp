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
    int n, odd = 0, even = 0;
    cin >> n;
    v(int) ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        if(ar[i] & 1) {
            odd++;
        }
        else even++;
    }
    sort(ar.begin(), ar.end());
    bool res = false;
    if(odd % 2 == 0 && even % 2 == 0) {
        cout << "YES" << endl;
        return;
    }
    odd = odd % 2;
    even = even % 2;
    int p = 0;
    for(int i = 1; i < n; i++) {
        if(ar[i] - ar[i-1] == 1) {
            p++;
            break;
        }
    }
    if(p) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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