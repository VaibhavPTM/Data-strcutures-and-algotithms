// Link : https://leetcode.com/problems/remove-duplicate-letters/
// Topic : Remove Duplicate Letters
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
string removeDuplicateLetters(string s)
{
    unordered_map<char, int> mp;   // this will keep the count of char and decrease when char will visited
    unordered_map<char, bool> mp2; // this will keep current char is in stack or not
    string res;                    // work as a stack
    for (char &i : s)
    {
        mp[i]++;
        mp2[i] = false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (mp2[c])
        {            // if curr char is already in stack them we will not cheack it
            mp[c]--; // decrease char
            continue;
        }
        while (res.size() > 0 && res.back() > c && mp[res.back()] > 0)
        {
            // if last char, we added is larger then curr and that last char we can get in later then we remove back char
            mp2[res.back()] = false;
            res.pop_back();
        }
        res.push_back(c);
        mp[c]--;
        mp2[c] = true;
    }
    return res;
}
int main()
{
    // Constraints:
    //     1 <= s.length <= 104
    //     s consists of lowercase English letters.

    return 0;
}