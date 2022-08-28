// Link : https://cses.fi/problemset/task/1073
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if(it == s.end()) {

            s.insert(x);
        }
        else {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size();
    return 0;
}