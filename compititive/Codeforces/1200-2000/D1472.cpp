// Link : https://codeforces.com/problemset/problem/1472/D
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define vv(T) vector<vector<T>>
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T>, greater<T>>
#define pb push_back
#define ff first
#define ss second
#define print(x)      \
    for (auto it : x) \
        cout << it << " ";
#define mem(n, i) memset(n, i, sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.rbegin(), v.rend());
    lli res = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (v[i] % 2 == 0) {
                res += v[i];
            }
        }
        else {
            if (v[i] % 2 == 1) {
                res -= v[i];
            }
        }
    }
    if (res == 0) {
        cout << "Tie\n";
    }
    else if (res > 0) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}