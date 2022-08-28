// Link : 
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
    int n, k;
    cin >> n >> k;
    v(int) arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0;
    while(k && i < n-1) {
        if(arr[i] <= k) {
            arr[n-1] += arr[i];
            k -= arr[i];
            arr[i++] = 0;
        }
        else {
            arr[i] -= k;
            arr[n-1] += k;
            k = 0;
        }
    }
    print(arr);
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