// Link : https://leetcode.com/problems/maximum-product-of-word-lengths/
// Topic :  Maximum Product of Word Lengths
// better inderstand - https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1365521/Java-3-solutions-from-worst-to-best-along-with-explaination
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
int maxProduct(vector<string> &w)
{
    int n = w.size();
    vector<int> arr(n, 0);
    int res = 0;
    for (int i = 0; i < w.size(); i++)
    {
        for (char &c : w[i])
        {
            arr[i] |= (1 << c - 'a');
        }
    }
    for (int i = 0; i < w.size(); i++)
    {
        for (int j = i + 1; j < w.size(); j++)
        {
            if ((arr[i] & arr[j]) == 0)
            {
                if (res < w[i].size() * w[j].size())
                {
                    res = w[i].size() * w[j].size();
                }
            }
        }
    }
    return res;
}
int main()
{
    // Constraints:
    //     2 <= words.length <= 1000
    //     1 <= words[i].length <= 1000
    //     words[i] consists only of lowercase English letters.
    return 0;
}