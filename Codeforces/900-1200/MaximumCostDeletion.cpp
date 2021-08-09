// Link : https://codeforces.com/problemset/problem/1550/B (1000)
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, grater<int>>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int res = n * a;
        if (b >= 0)
        {
            res += b * n;
        }
        else
        {
            int tt = 0;
            for (int i = 1; i < n; i++)
            {
                if (s[i - 1] != s[i])
                    tt++;
            }
            tt++;
            res += ((tt / 2) + 1) * b;
        }
        cout << res << endl;
    }
    return 0;
}