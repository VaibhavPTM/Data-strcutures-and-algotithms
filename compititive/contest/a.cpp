#include <bits/stdc++.h>
#include <stdio.h>
#include "string.h"
using namespace std;
#define int long long
#define float double
#define pb push_back
#define all(x) x.begin(), x.end()
#define con(s1, s2) strstr(s1.c_str(), s2.c_str())
#define foreach(x, y) for (auto &x : y)
#define allr(x) x.rbegin(), x.rend()
#define sum(a) accumulate(a.begin(), a.end(), (int)0)
#define ff first
#define ss second
#define vi vector<int>
#define pi pair<int, int>
int M = 998244353;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(0) << fixed;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        sort(allr(v));

        int sum = v[0] + v[1];

        int ans = 2 * (k / sum);
        k -= (k / sum) * sum;
        if (k > 0)
        {
            ans++;
            k -= v[0];
        }
        if (k > 0)
            ans++;
        cout << ans << endl;
    }

    return 0;
}