// Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
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
#define endl "\n"

map<char, string> mp;

void solve(vector<string> & ans,string input, string output){
    if(input.size() == 0){
        ans.push_back(output);
        return;
    }
    string temp = mp[input[0]];
    input.erase(input.begin());
    vector<string> t;
    for (int i = 0; i < temp.size(); i++){
        t.push_back(output);
        t[i].push_back(temp[i]);
    }
    for (int i = 0; i < t.size(); i++)
    {
        solve(ans,input,t[i]);
    }

}

vector<string> letterCombinations(string digits){
    vector<string> ans;
    if (digits.size() == 0)
        return ans;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    string t = "";
    solve(ans,digits,t);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> v = letterCombinations(s);

    for (auto i : v){
        cout<<i<<" ";
    }
    
    return 0;
}