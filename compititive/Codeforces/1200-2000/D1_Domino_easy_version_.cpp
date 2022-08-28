// Link : https://codeforces.com/contest/1551/problem/D1
// Topic : constructive algorithms    math    *1700
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
#define MAX 100001

int arr[MAX];

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    if (M & 1)
        M--;
    if (N & 1)
        N--, K -= M / 2;
    cout << (0 <= K && K <= N * M / 2 && K % 2 == 0 ? "YES" : "NO") << "\n";
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