// Link : https://leetcode.com/problems/palindrome-pairs/
// Name : Palindrome Pairs
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> palindromePairs(vector<string> &w)
{
    unordered_map<string, int> mp;
    vector<vector<int>> res;
    for (int i = 0; i < w.size(); i++){
        mp[w[i]] = i;
    }
    for (int i = 0; i < w.size(); i++){
        string tmp = w[i];
        if (tmp == ""){
            for (int j = 0; j < w.size(); j++){
                if (i == j)
                    continue;
                if (is_pali(w[j], 0, w[j].size() - 1)){
                    res.push_back({i, j});
                    res.push_back({j, i});
                }
            }
            continue;
        }
        reverse(tmp.begin(), tmp.end());
        if (mp.find(tmp) != mp.end()){
            if (mp[tmp] != i)
                res.push_back({i, mp[tmp]});
        }
        for (int j = 1; j < tmp.size(); j++){
            if (is_pali(tmp, 0, j - 1)){
                string s = tmp.substr(j, tmp.size() - j);
                if (mp.find(s) != mp.end()){
                    res.push_back({i, mp[s]});
                }
            }
            if (is_pali(tmp, j, tmp.size() - 1)){
                string s = tmp.substr(0, j);
                if (mp.find(s) != mp.end()){
                    res.push_back({mp[s], i});
                }
            }
        }
    }
    return res;
}

int main()
{
    // Constraints:
    //     1 <= words.length <= 5000
    //     0 <= words[i].length <= 300
    //     words[i] consists of lower-case English letters.

    return 0;
}