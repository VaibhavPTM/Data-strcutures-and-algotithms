// Link : https://codeforces.com/problemset/problem/1529/B
// Topic :   greedy    math    sortings    *1100
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
    lli n, negEl = 0, zeros = 0, mxN0 = INT_MAX;
    cin >> n;
    v(lli) arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] < 0) negEl++;
        else if(arr[i] == 0) zeros++;
        else if(arr[i] > 0) mxN0 = min(mxN0, arr[i]);
    }
    sort(arr.begin(),arr.end(),greater<lli>());
    if(arr.size() == 1) cout << 1 << endl;
    else if(negEl == 0){
        if(zeros > 1) cout << zeros << endl;
        else cout << (zeros > 0 ? 1 : 0) + 1 << endl;
    }
    else if(arr[0] <= 0) {
        cout << n << endl;
    }
    else {
        for(int i = 1; i < n; i++) {
            if(arr[i] >= mxN0) continue;
            else {
                if(abs(arr[i] - arr[i-1]) < mxN0) {
                    cout << negEl + zeros << endl;
                    return;
                }
            }
        }
        cout << negEl + zeros + 1 << endl;
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