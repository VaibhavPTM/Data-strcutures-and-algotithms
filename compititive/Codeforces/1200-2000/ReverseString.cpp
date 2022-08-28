// Link : https://codeforces.com/problemset/problem/1553/B
// Topic : brute force, dp, hashing, implementation, string (1300)
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
int left(string s, string t, int i, int x) {
    while (x < t.length() && i >= 0) {
        if (t[x] == s[i]) {
            x++;
            i--;
        }
        else {
            break;
        }
    }
    if (x == t.length()) {
        return 1;
    }
    return 0;
}
 
int right(string s, string t, int i, int x)
{
    if (x == t.length()) {
        return 1;
    }
    if (x + 1 == t.length()) {
        if (i + 1 < s.length() && s[i + 1] == t[x]) {
            return 1;
        }
        else if (i - 1 >= 0 && s[i - 1] == t[x]) {
            return 1;
        }
        else {
            return 0;
        }
    }
 
    int r1 = 0, r2 = 0;
    if (i - 1 >= 0 && s[i - 1] == t[x]) {
        r1 = left(s, t, i - 1, x);
    }
    if (r1) {
        return 1;
    }
    if (i + 1 < s.length() && s[i + 1] == t[x]) {
        r2 = right(s, t, i + 1, x + 1);
    }
 
    return (r1 || r2);
}


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        bool l = false;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[0]) {
                l = right(a, b, i, 1);
                if(l) break;
            }
        }
        if (l)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}