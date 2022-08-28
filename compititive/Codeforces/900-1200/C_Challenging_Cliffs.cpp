// Link : https://codeforces.com/problemset/problem/1537/C
// Topic :  constructive algorithms    greedy    implementation    math    *1200
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
#define MAX 100001
// slution 1
void solve() {
    lli n;
    cin >> n;
    v(lli) ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end());
    lli dif = INT_MAX, x, y;
    for(int i = 1; i < n; i++) {
        if(dif > ar[i] - ar[i-1]) {
            dif = ar[i] - ar[i-1];
            x = i-1, y = i;
        }
    }
    v(lli) res(n);
    //     x y
    // 1 2 3 3 5 6 7 8
    // 3 5 6 7 8 1 2 3
    res[0] = ar[x];
    res[n-1] = ar[y];
    int j = 1;
    for(int i = y+1; i < n; i++,j++) {
        res[j] = ar[i];
    }
    for(int i = 0; i < x; i++,j++) {
        res[j] = ar[i];
    }
    print(res);
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
// Solution 2
/* void solve() {
    lli n;
    cin >> n;
    v(lli) ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end());
    lli dif = INT_MAX, x, y;
    for(int i = 1; i < n; i++) {
        if(dif > ar[i] - ar[i-1]) {
            dif = ar[i] - ar[i-1];
            x = i-1, y = i;
        }
    }
    v(lli) res(n);
    //     x y
    // 1 3 6 7 15 16 17 18
    // 7 15 16 17 18 1 3 6
    for(int i = y, j = 0; i < n; i++,j++) {
        res[j] = ar[i];
    }
    for(int i = 0, j = n - y; i < y; i++,j++) {
        res[j] = ar[i];
    }
    swap(res[0],res[n-1]);
    print(res);
    cout << endl;

} */