// Link : https://leetcode.com/problems/search-suggestions-system/
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class Trie
{
public:
    unordered_map<char, Trie *> mp;
    bool isEnd = false;
    vector<int> idx;
};
Trie *root;
void insert(string s, int index)
{
    Trie *tmp = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (tmp->mp[s[i]] == NULL)
        {
            tmp->mp[s[i]] = new Trie();
        }
        tmp = tmp->mp[s[i]];
        tmp->idx.push_back(index);
    }
    tmp->isEnd = true;
}
void help(vector<string> &p, string s, vector<vector<string>> &res)
{
    Trie *tmp = root;
    bool f = false;
    for (char c : s)
    {
        vector<string> tmpRes;
        if (f || tmp->mp[c] == NULL)
        {
            f = true;
        }
        else
        {
            tmp = tmp->mp[c];
            int len = tmp->idx.size();
            if (len > 3)
                len = 3;
            for (int i = 0; i < len; i++)
            {
                tmpRes.push_back(p[tmp->idx[i]]);
            }
        }
        res.push_back(tmpRes);
    }
}
vector<vector<string>> suggestedProducts(vector<string> &p, string sw)
{
    root = new Trie();
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); i++)
    {
        insert(p[i], i);
    }
    vector<vector<string>> res;
    help(p, sw, res);
    return res;
}

int main()
{
    // Constraints:
    //     1 <= products.length <= 1000
    //     There are no repeated elements in products.
    //     1 <= Σ products[i].length <= 2 * 10^4
    //     All characters of products[i] are lower-case English letters.
    //     1 <= searchWord.length <= 1000
    //     All characters of searchWord are lower-case English letters.
    return 0;
}