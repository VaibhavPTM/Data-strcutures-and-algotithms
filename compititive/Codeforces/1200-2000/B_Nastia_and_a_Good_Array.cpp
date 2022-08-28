// Link : https://codeforces.com/contest/1521/problem/B
// Topic :  constructive algorithms    math    number theory    *1300
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

int arr[MAX];

void solve() {
    // https://codeforces.com/blog/entry/90477 - read it
    int n , x;
    cin >> n;
    int pos, mn = INT_MAX;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x < mn) {
            mn = x;
            pos = i;
        }
    }
    // don't need to minimize the opration so change as much as posible 
    cout << n-1 << endl;
    for(int i = 1; i <= n; i++) {
        if(i == pos) continue;
        else cout << pos << " " << i << " " << mn << " " << mn + abs(i - pos) << endl;
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