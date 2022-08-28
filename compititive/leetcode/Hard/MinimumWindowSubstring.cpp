// Link : https://leetcode.com/problems/minimum-window-substring/
// Topic :
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
string minWindow(string s, string t)
{
    int len = INT_MAX, j = 0, cnt = t.size(), start = 0;
    vector<int> mp(126, 0);
    for (char &i : t)
        mp[i]++;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] > 0)
        {
            cnt--;
        }
        mp[s[i]]--;
        while (!cnt and i >= j)
        {
            if (i - j + 1 < len)
            {
                len = i - j + 1;
                start = j;
            }
            mp[s[j]]++;
            if (mp[s[j++]] > 0)
            {
                cnt++;
            }
        }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    cout << minWindow(s,t);
    return 0;
}