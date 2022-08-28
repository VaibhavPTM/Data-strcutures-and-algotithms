// Link : https://codeforces.com/problemset/problem/1538/A
// Topic :   brute force    dp    greedy    800*
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
#define endl "\n"
#define MAX 100001

int arr[MAX];

void solve() {
    int n;
    cin >> n;
    int a1, an;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x == 1) a1 = i;
        if(x == n) an = i;
    }
    int mn = min(a1,an);
    int mx = max(a1,an);
    // int res = min(mx, n - mn + 1);
    // res = min(res, mn + (n - mx + 1));
    // cout << res << endl;
    cout <<  min(min(mx, n - mn + 1), mn + (n - mx + 1)) << endl;

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