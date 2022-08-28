// Link : https://codeforces.com/problemset/problem/1506/B
// Topic :  greedy    implementation    *1100
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T>, greater<T>>
#define pb push_back
#define ff first
#define ss second
#define print(x)      \
    for (auto it : x) \
        cout << it << " ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "#" + s;
    int i = 1, res = 0, last = 0;
    while (i <= n && s[i] != '*') {
        i++;
    }
    while (n >= i && s[n] != '*') {
        n--;
    }
    last = i;
    if(i > n) res = 0;
    else if(i == n)
        res = 1;
    else res = 2;
    for (int j = i + 1; j < n; j++) {
        if (j - i < k) {
            if (s[j] == '*') {
                last = j;
            }
        }
        else if (j - i == k) {
            if (s[j] == '*') {
                i = j;
            }
            else
                i = last;
            res++;
        }
    }
    cout << res << endl;
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
