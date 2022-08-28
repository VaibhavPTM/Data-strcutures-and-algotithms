// Link : https://codeforces.com/problemset/problem/1534/B
// Topic :  greedy    implementation    math    *1100
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
#define MAX 100001 * 4

void solve() {
    int n;
    cin >> n;
    v(lli) arr(n+2);
    arr[0] = arr[n+1] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // greedy - if bar is grater them his both neighbour the cut it
    lli res = 0;
    for(int i = 1; i <= n+1; i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int t = abs(arr[i] - max(arr[i-1],arr[i+1]));
            arr[i] -= t;
            res += t + abs(arr[i] - arr[i-1]);
        }
        else {
            res += abs(arr[i] - arr[i-1]);
        }
    }
    cout << res << endl;
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