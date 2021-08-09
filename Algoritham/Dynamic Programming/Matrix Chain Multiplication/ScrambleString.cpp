// Link : https://leetcode.com/problems/scramble-string/
// Link : https://www.interviewbit.com/problems/scramble-string/
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
bool isScramble(string s1, string s2)
{
    if (s1 == s2)
    {
        return true;
    }
    else if (s2.size() != s1.size())
        return false;
    else if (s1.size() <= 1)
        return false;
    string k = s1 + "*" + s2;
    if (mp.find(k) != mp.end())
    {
        return mp[k];
    }
    int n = s1.size();
    for (int i = 1; i < s1.size(); i++)
    {
        bool con1 = isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i));
        bool con2 = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i));
        if (con1 || con2)
        {
            return mp[k] = true;
        }
    }
    return mp[k] = false;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (isScramble(s1, s2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}