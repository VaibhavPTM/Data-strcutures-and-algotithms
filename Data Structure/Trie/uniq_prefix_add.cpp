
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    class Trie {
        public :
            Trie * node[28];
            int count[28];
        Trie () {
            for(int i = 0; i < 28; i++) {
                count[i] = 0;
                node[i] = NULL;
            }
        }
    };
    Trie *root;
    void insert(string word){
        Trie* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->node[word[i] - 'a'] == NULL){
                curr->node[word[i] - 'a'] = new Trie();
            }
            curr->count[word[i] - 'a']++;
            curr = curr->node[word[i] - 'a'];
        }
    }
    string search(string word) {
        string res;
        Trie * curr = root;
        if(curr == NULL) curr = new Trie();
        for(int i = 0; i < word.size(); i++){
            res.push_back(word[i]);
            if(curr->count[word[i] - 'a'] == 1){ 
                return res;
            }
            curr = curr->node[word[i] - 'a'];
        }
        return res;
    }
    
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        root = new Trie();
        vector<string> res;
        for(int i = 0; i < n; i++) {
            insert(arr[i]);
        }
        for(int i = 0; i < n; i++) {
            res.push_back(search(arr[i]));
        }
        return res;
    }
    
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";
        cout << "\n";
    }
    return 0;
}