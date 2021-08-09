// Link : https://leetcode.com/problems/longest-palindromic-substring/
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
string longestPalindrome(string s)
{
    int len = s.length();
    string res = "";

    for (; len >= 1; len--){ //for length of pallindrome starting with full length

        for (int i = 0; i + len - 1 < s.length(); i++){ //checking if pallindrome present with that                                                                                                                   //length
            int j = i;
            int k = i + len - 1;
            res = "";
            while (j < k){
                if (s[j] == s[k]){
                    j++;
                    k--;
                }
                else
                {
                    break;
                }
            }
            if (j >= k){                            //if pallindrome present with that length
                return s.substr(i, len); //As we are checking from longest possible length.
                                         //So, this is the longest
            }
        }
    }
    return s.substr(0, 1);
}
int main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s);
    return 0;
}