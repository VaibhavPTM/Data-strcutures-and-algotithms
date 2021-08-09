// Link : https://leetcode.com/problems/shortest-palindrome/
// Topic :
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

string shortestPalindrome(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    string l = s + "#" + rev;
    vector<int> f(l.size(), 0);
    for (int i = 1; i < l.size(); i++){
        int t = f[i - 1];
        while (t > 0 && l[i] != s[t]){
            t = f[t - 1];
        }
        if (l[i] == s[t])
            ++t;
        f[i] = t;
    }
    return rev.substr(0, s.size() - f[l.size() - 1]) + s;
}
int main(){
    string s;
    cin>>s;
    cout<<shortestPalindrome(s);

    return 0;
}