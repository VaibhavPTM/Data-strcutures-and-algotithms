// Link : https://codeforces.com/problemset/problem/1557/B
// Topic :   greedy    sortings    *1100
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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int> > vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i].first;
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    int res = 1;
    // 2, 3, 1, 6, 0
    // 0, 1, 2, 3, 6
    for(int i = 0; i < n-1; i++) {
        if(vec[i].second + 1 != vec[i+1].second) {
            res++;
        }
    }
    if(k < res) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
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