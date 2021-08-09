// Link : https://leetcode.com/problems/implement-trie-prefix-tree/
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public :
        TrieNode *node[26];
        bool wordEnd = false;
};

TrieNode *root;

void insert(string word){
    TrieNode* curr = root;
    for(int i = 0; i < word.size(); i++){
        if(curr->node[word[i] - 'a'] == NULL){
            curr->node[word[i] - 'a'] = new TrieNode();
        }
        curr = curr->node[word[i] - 'a'];
    }
    curr->wordEnd = true;
}

bool search(string word) {
    TrieNode * curr = root;
    for(int i = 0; i < word.size(); i++){
        if(curr->node[word[i] - 'a'] == NULL) return false;
        curr = curr->node[word[i] - 'a'];
    }
    if(curr->wordEnd != true) return false;
    return true;
}

bool startsWith(string word) {
    TrieNode * curr = root;
    for(int i = 0; i < word.size(); i++){
        if(curr->node[word[i] - 'a'] == NULL) return false;
        curr = curr->node[word[i] - 'a'];
    }
    return true;
}
int main()
{
    root = new TrieNode();

    insert("vaibhav");
    if(search("vaibhav")) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    if(startsWith("vaix")) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}