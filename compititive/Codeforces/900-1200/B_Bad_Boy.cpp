// Link : https://codeforces.com/problemset/problem/1537/B
// Topic :   constructive algorithms    greedy    math    900*
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
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    // first pair is n - 1 & 1 - m;
    // we alwaye thorw yo yo at two corners of grid
    cout << n << " " << 1 << " " << 1 << " " << m << endl;

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