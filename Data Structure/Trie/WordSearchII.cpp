// Link : https://leetcode.com/problems/word-search-ii/
// Topic : Trie (Hard)
#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    Trie *node[26];
    bool isEnd;
};
Trie *root;


void addword(string str)
{
    Trie *curr = root;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i] - 'a';
        if (curr->node[c] == NULL)
            curr->node[c] = new Trie();
        curr = curr->node[c];
    }
    curr->isEnd = true;
    // return 0;
}

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
vector<string> ans;
int n, m;
void find(vector<vector<char>> &b, int i, int j, Trie *root, string &res)
{
    if (b[i][j] == ' ')
        return;
    if (root->node[b[i][j] - 'a'] == NULL)
        return;
    res += b[i][j];
    if (root->node[b[i][j] - 'a']->isEnd)
    {
        ans.push_back(res);
        root->node[b[i][j] - 'a']->isEnd = false;
    }
    char c = b[i][j];
    b[i][j] = ' ';
    for (int k = 0; k < 4; k++)
    {
        int ii = i + x[k];
        int jj = j + y[k];
        if (ii >= 0 && ii < n && jj >= 0 && jj < m && b[ii][jj] != ' ')
            find(b, ii, jj, root->node[c - 'a'], res);
    }
    b[i][j] = c;
    res.pop_back();
}

vector<string> findWords(vector<vector<char>> &b, vector<string> &words)
{
    root = new Trie();
    for (auto i : words)
        addword(i);
    n = b.size();
    m = b[0].size();
    string tmp = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            find(b, i, j, root, tmp);
        }
    }

    return ans;
}

int main()
{
    /* 
    Constraints:
        m == board.length
        n == board[i].length
        1 <= m, n <= 12
        board[i][j] is a lowercase English letter.
        1 <= words.length <= 3 * 104
        1 <= words[i].length <= 10
        words[i] consists of lowercase English letters.
        All the strings of words are unique.
    */
    vector<vector<char>> b = { {'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'} };
    vector<string> words = {"oath","pea","eat","rain"};

    vector<string> res = findWords(b,words);

    for(auto i : res) cout<<i<<endl;

    return 0;
}
