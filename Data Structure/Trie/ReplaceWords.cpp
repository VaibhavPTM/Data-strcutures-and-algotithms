// Link : https://leetcode.com/problems/replace-words/
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
class trie
{
public:
    trie *node[26];
    bool isEnd;
    int wIdx; // this will give you the word index of dictionary
    trie()
    {
        for (int i = 0; i < 26; i++)
        {
            node[i] = NULL;
            isEnd = false;
            wIdx = INT_MIN;
        }
    }
};
trie *root;
void insert(string word, int idx)
{
    trie *tmp = root;
    for (int i = 0; i < word.size(); i++)
    {
        int c = word[i] - 'a';
        if (tmp->node[c] == NULL)
        {
            tmp->node[c] = new trie;
        }
        tmp = tmp->node[c];
        // if you added a then you don't need to insert aa aaa abb axx...(basically starts from a)
        if (tmp->isEnd)
            return;
    }
    tmp->isEnd = true;
    tmp->wIdx = idx;
}
int search(string word)
{
    trie *tmp = root;
    for (int i = 0; i < word.size(); i++)
    {
        int c = word[i] - 'a';
        if (tmp->node[c] == NULL)
            return INT_MIN;
        tmp = tmp->node[c];
        if (tmp->isEnd == true)
            return tmp->wIdx;
    }
    return INT_MIN;
}

string replaceWords(vector<string> &dict, string sect)
{
    root = new trie();
    string res = "";
    for (int i = 0; i < dict.size(); i++)
    {
        insert(dict[i], i);
    }
    for (int i = 0; i < sect.size(); i++)
    {
        string s;
        while (i < sect.size() && sect[i] != ' ')
        {
            s += sect[i];
            i++;
        }
        // cout<<s<<endl;
        int curr_idx = search(s);
        if (curr_idx == INT_MIN)
        {
            res += s + ' ';
        }
        else
        {
            res += dict[curr_idx] + ' ';
        }
    }
    res.pop_back();
    return res;
}
int main()
{
// Constraints:
//         1 <= dictionary.length <= 1000
//         1 <= dictionary[i].length <= 100
//         dictionary[i] consists of only lower-case letters.
//         1 <= sentence.length <= 10^6
//         sentence consists of only lower-case letters and spaces.
//         The number of words in sentence is in the range [1, 1000]
//         The length of each word in sentence is in the range [1, 1000]
//         Each two consecutive words in sentence will be separated by exactly one space.
//         sentence does not have leading or trailing spaces.
    return 0;
}