// Link : https://codeforces.com/problemset/problem/1519/A
// Topic : 
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
    int r, b, d;
    cin >> r >> b >> d;
    int dd = abs(r- b);
    if(dd <= d) {
        cout << "YES" << endl;
    }   
    else{
        if(d == 0 || (r == 1 || b == 1)) {
            cout << "NO" << endl;
        }
        else {
            dd = ceil((float)dd/ (float)d); 
            if(dd > min(r,b)) cout << "NO" << endl;
            else cout << "YES" << endl;  
        }
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