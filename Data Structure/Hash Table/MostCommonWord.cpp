// Link = https://leetcode.com/problems/most-common-word/
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
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define fors(j, s, n) for (int j = s; j < n; j++)
#define mod 1000000007
#define sin(n) scanf("%d", &n)
#define endl "\n"
string mostCommonWord(string para, vector<string> &ban)
{
    unordered_map<string, int> mp;
    int i = 0;
    while (i < para.size())
    {
        string s = "";
        while (i < para.size() && isalpha(para[i]))
        {
            s.push_back(tolower(para[i]));
            i++;
        }
        if (s != "")
        {
            mp[s]++;
        }
        i++;
    }
    for (auto b : ban)
    {
        mp.erase(b);
    }
    int _max = 0;
    string res = "";
    for (auto m : mp)
    {
        if (_max < m.second)
        {
            _max = m.second;
            res = m.first;
        }
    }
    return res;
}
int main()
{
    string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> v_str = {"hit"};
    int n;
    // cin >> n;
    // cin >> str;
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     v_str.push_back(s);
    // }
    cout << mostCommonWord(str, v_str);

    return 0;
}