// Link : https://leetcode.com/problems/design-add-and-search-words-data-structure/
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

class Trie{
public:
    Trie *Node[26];
    bool lw = false;
};
Trie *root;

void addWord(string word){
    Trie *curr = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (curr->Node[word[i] - 'a'] == NULL)
        {
            curr->Node[word[i] - 'a'] = new Trie();
        }
        curr = curr->Node[word[i] - 'a'];
    }
    curr->lw = true;
}

bool searchHelp(string word, int idx, Trie *node){
    if (idx == word.size()){
        return node->lw;
    }
    else if (word[idx] != '.'){
        if (node->Node[word[idx] - 'a'] == NULL)
            return false;
        return searchHelp(word, idx + 1, node->Node[word[idx] - 'a']);
    }
    else{
        bool flg = false;
        for (int i = 0; i < 26; i++){
            if (node->Node[i] != NULL && searchHelp(word, idx + 1, node->Node[i])){
                flg = true;
                break;
            }
        }
        return flg;
    }
}
bool search(string word){
    return searchHelp(word, 0, root);
}
int main() {
    root = new Trie();

    // inputs
//     Constraints:
//     1 <= word.length <= 500
//     word in addWord consists lower-case English letters.
//     word in search consist of  '.' or lower-case English letters.
//     At most 50000 calls will be made to addWord and search

// Give input your self

    return 0;
}