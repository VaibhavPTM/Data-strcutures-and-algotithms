// Link : https://cses.fi/problemset/task/1091
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    int pay[m];
    multiset<int,greater<int> > s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i = 0; i < m; i++) {
        cin >> pay[i];
    }
    for(int i = 0; i < m; i++) {
        // it finds the lower bound of currunt value and if it is not available return the end pointer
        auto it = s.lower_bound(pay[i]);
        if(it == s.end()) {
            cout << -1 << endl;
        }
        else {
            cout << *it << endl;
            s.erase(it);
        }
    }
}