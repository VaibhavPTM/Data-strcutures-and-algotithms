#include <bits/stdc++.h>
#include <stdio.h>
#include "string.h"
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define con(s1, s2) strstr(s1.c_str(), s2.c_str())
#define foreach(x, y) for (auto &x : y)
#define allr(x) x.rbegin(), x.rend()
#define sum(a) accumulate(a.begin(), a.end(), (int)0)
#define ff first
#define ss second
#define pi pair<int, int>
int M = 1e9 + 7;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(5) << fixed;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, ss;
        cin >> s >> ss;
        vector<int> vs(n), vss(n);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            vs[i] = s[i] - '0';
            vss[i] = ss[i] - '0';
            if (i > 0)
            {
                vs[i] += vs[i - 1];
                vss[i] += vss[i - 1];
                dp[0][i + 1] = (ss[i] == '0') ? vss[i] + dp[0][i] : dp[0][i];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = (s[i - 1] == '0') ? dp[i - 1][0] + vs[i - 1] : dp[i - 1][0];

            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == '0' && ss[j - 1] == '0')
                {
                    dp[i][j] = dp[i - 1][j - 1] + (vs[i - 1] + vss[j - 1]) * 2;
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + (vs[i - 1] + vss[j - 1]));
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + (vs[i - 1] + vss[j - 1]));
                }
                else if (s[i - 1] == '0' && ss[j - 1] == '1')
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (s[i - 1] == '1' && ss[j - 1] == '0')
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
                }
            }
        }

        cout << dp.back().back() << endl;
    }

    return 0;
}