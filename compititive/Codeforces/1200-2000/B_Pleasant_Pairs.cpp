// Link : https://codeforces.com/problemset/problem/1541/B
// Topic :  brute force    implementation    math    number theory    *1200
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

void solve() {
    lli n;
    cin >> n;
    vector<pair<int,int>> arr(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    int res = 0, mx = n * 2 - 1;
    sort(arr.begin(),arr.end());
    for(int i = 1; i < n; i++) {
        if(arr[i].first * arr[i+1].first > mx) break;
        for(int j = i + 1; j <= n; j++) {
            if(arr[i].first * arr[i+1].first > mx) break;
            else if(arr[i].first * arr[j].first == arr[i].second + arr[j].second) res++;
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