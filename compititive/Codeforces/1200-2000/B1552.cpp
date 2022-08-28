// Link : https://codeforces.com/problemset/problem/1552/B
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
struct Rank {
    int r[5];
};

bool operator<(const Rank&a, const Rank&b) {
    int cnt = 0;
    for(int i = 0; i < 5; i++) {
        cnt += a.r[i] < b.r[i];
    }
    return cnt >= 3;
}

void solve() {
    int n;
    cin >> n;
    vector<Rank> ar(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> ar[i].r[j];
        }
    }
    int gold = 0;
    for(int i = 0; i < n; i++) {
        if(ar[i] < ar[gold]) gold = i;
    }

    for(int i = 0;i < n; i++) {
        if(i == gold) continue;
        if(ar[i] < ar[gold]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << gold+1 << endl;

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